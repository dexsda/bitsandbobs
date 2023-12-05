#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* https://math.stackexchange.com/questions/1270814/bounds-for-n-th-prime */ 
int upper_bound(int n) {
    if(n >= 6)
        return ceil(n*(log(n) + log(log(n))));
    else
        return 11;
}

int main(void) {
    char * sieve;
    int n, bound, i, j;

    printf("Podaj ilość liczb pierwszych: ");
    scanf("%d", &n);

    sieve = calloc(bound = upper_bound(n), sizeof(char));

    for (i = 2; n; i++){
        if(!sieve[i]){
            printf("%d, ", i);
            n--;
            for (j = i*2; j <= bound; j+= i)
                sieve[j] = 1;
        }
    }

    free(sieve);
    return 0;
}
