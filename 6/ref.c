#include <stdio.h>
#include <stdlib.h>

#include "golden.h"

int * fib_numbers;

void calc_fibonacci(int n){
    fib_numbers = calloc(n, sizeof(int));
    fib_numbers[0] = 0;
    fib_numbers[1] = 1;
    for (int i = 2; i < n; i++) 
        fib_numbers[i] = fib_numbers[i-1]+ fib_numbers[i-2];
}

int fib(int n){
    if (n >= 0) {
        return fib_numbers[n];
    } else {
        return n % 2 ? fib(-n) : -fib(-n);
    }
}

golden nth_power(int n){
    golden result = {fib(n-1), fib(n)};
    return result;
}

int find_largest_power(golden x){
    int pow = 0;
    while(value(subtract(x, nth_power(pow))) >= 0.0)
        pow++;

    return pow-1;
}

int main (void) {
    calc_fibonacci(128);
    char buffer[256] = {};
    int liczba;

    printf("Podaj liczbę naturalną do konwersji do systemu φ: ");
    scanf("%d", &liczba);

    golden current = {liczba, 0}, temp;
    
    int power = find_largest_power(current), i = 0;
    while (current.whole || current.phi) {
        if (value(temp = subtract(current, nth_power(power))) < 0.0) {
            buffer[i++] = '0';
        } else {
            buffer[i++] = '1';
            current = temp;
        }

        if (power == 0)
            buffer[i++] = '.';
        
        power--;
    }
    
    printf("Liczba %d w systemie φ to: %s\n", liczba, buffer);

    return 0;
}
