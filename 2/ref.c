#include <stdio.h>

int sum(int num){
    int sum = 0;
    while (num){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(){
    int d, m, y;

    printf("Podaj datę urodzenia w formacie DD-MM-YYYY: ");
    scanf("%d-%d-%d", &d, &m, &y);

    int number = sum(d) + sum(m) + sum(y);

    while (number > 9 && (number % 11 || number > 33))
        number = sum(number);

    printf("Liczba numerologiczna dla daty %d-%d-%d to %d!\n", d, m, y, number);
    if(! number % 11)
        printf("Jest to liczba mistrzowska!\n");

    return 0;
}
