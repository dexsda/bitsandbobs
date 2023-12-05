#include <stdio.h>
#include <math.h>

#define PHI (1.0 + sqrt(5))/2.0

typedef struct {
    int whole;
    int phi;
} golden;

golden subtract(golden a, golden b){
    golden result = {a.whole - b.whole, a.phi - b.phi};
    return result;
}

void print(golden x){
    printf("%d + %d φ\n", x.whole, x.phi);
}

double value(golden x){
    return x.phi * PHI + x.whole;
}

