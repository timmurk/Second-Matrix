#include <stdlib.h>
#include <stdio.h>

double checkTrace(double *a, int n, int key);
double checkNorm(double *a, int n, int key);
void printMatrix(int n, double* a, int v_size);
void printEVal(int n, double* e_val, int v_size);
double f(int i, int j, int n);
int inputMatrix(int c, FILE *in, int n, double *a, double *e_val);
