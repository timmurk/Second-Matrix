#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double checkTrace(double *a, int n, int key) {
    double s = 0.0;
    if (key == 0) {
        for (int i = 0; i < n; i++) {
            s -= a[i*n+i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            s += a[i];
        }
    }
    return s;
}

double checkNorm(double *a, int n, int key) {
    double s = 0.0;
    if (key == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s += a[i*n + j]*a[j*n + i];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            s += a[i]*a[i];
        }
    }
    return sqrt(s);
}

void printMatrix(int n, double *a, int v_size) {
    int sz = min(n,v_size);
    for (int i =0; i < sz; i++){
        for (int j = 0; j < sz; j++) {
            printf("%0.3lf ",a[i*n+j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printEVal(int n, double* e_val, int v_size) {
    int sz = min(n,v_size);
    for (int i = 0; i < sz; i++) {
        printf("%0.3lf ", e_val[i]);
    }
    printf("\n");
}


double f(int i, int j, int n) {
    if (i == j && i < n/2) {
        return 1;
    }
    if (i == n/2 && j <= n/2) {
        return i;
    }
    if (j == n/2 && i <= n/2) {
        return j;
    }
    if (i > n/2 && j > n/2) {
        if (i == j) {
            return 2;
        }
        if (fabs(i-j) == 1) {
            return -1;
        }
    }
    return 0;
}

int inputMatrix(int c, FILE *in, int n, double *a, double *e_val) {
    if (c == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (fscanf(in,"%lf",&a[i*n+j]) != 1) {
                    return -1;
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i*n + j] = f(i,j,n);
            }
        }
    }
    return 1;
}
