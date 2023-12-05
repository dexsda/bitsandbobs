#include <stdio.h>
#include <string.h>
#include <ctype.h>

int sum(int num){
    int sum = 0;
    while (num){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int calculate_numerology(int number) {
    while (number > 9 && (number % 11 || number > 33))
        number = sum(number);
    
    return number;
}

int translate_char(char ch){
    ch = tolower(ch);
    return 1 + ((ch - 'a') % 9);
}

int sum_chars(char * string){
    int i, sum = 0;
    for (i = 0; i < strlen(string); i++)
        sum += translate_char(string[i]);

    return sum;
}

int main(){
    int val, total = 0;
    char buffer[1000] = "";
    char * token;

    printf("Podaj swoje pełne nazwisko: ");
    fgets(buffer, 1000, stdin);

    token = strtok(buffer, " \n");

    do {
        val = sum_chars(token);
        printf("Suma dla %s: %d\n", token, calculate_numerology(val));
        total += val;
    } while ((token = strtok(NULL, " \n")));

    printf("Całość: %d\n", calculate_numerology(total));

    return 0;
}
