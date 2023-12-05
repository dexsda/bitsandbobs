#ifndef GOLDEN_H
#define GOLDEN_H

typedef struct {
    int whole;
    int phi;
} golden;

golden subtract(golden a, golden b);
void print(golden x);
double value(golden x);

#endif
