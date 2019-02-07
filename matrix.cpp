#include <math.h>
#include "input.h"

void Reflection(int n, double* a) {
    double tmp, norm, div;
    
    for (int i = 0; i < n - 2; i++) {
        
        tmp = 0;
        for (int j = i + 2; j < n; j++) {
            tmp += a[j * n + i] * a[j * n + i];
        }
        
        norm = sqrt(a[(i + 1) * n + i] * a[(i + 1) * n + i] + tmp);
        
        if (norm < 1e-100) {
            a[(i + 1) * n + i] = 0;
            a[(i + 2) * n + i] = 0;
        } else if (tmp < 1e-100) {
            a[(i + 2) * n + i] = 0;
        } else {
            a[(i + 1) * n + i] -= norm;
            //printMatrix(n,a,7);
            div = 1.0 / sqrt(a[(i + 1) * n + i] * a[(i + 1) * n + i] + tmp);
            for (int j = i + 1; j < n; j++) {
                a[j * n + i] *= div;
            }
            
            for (int j = i + 1; j < n; j++)
            {
                tmp = 0;
                for (int k = i + 1; k < n; k++)
                    tmp += a[k * n + i] * a[k * n + j];
                
                for (int k = i + 1; k < n; k++) {
                    a[k * n + j] -= 2 * tmp * a[k * n + i];
                }
            }
            for (int j = 0; j < n; j++) {
                tmp = 0;
                for (int k = i + 1; k < n; k++)
                    tmp += a[k * n + i] * a[j * n + k];
                
                for (int k = i + 1; k < n; k++) {
                    a[j * n + k] -= 2 * tmp * a[k * n + i];
                }
            }
            a[(i + 1) * n + i] = norm;
            for (int j = i + 2; j < n; j++) {
                a[j * n + i] = 0;
            }
            //printMatrix(n,a,7);
            //cout << "was here \n";
        }
    }
}

void eigValues(int n, double* a, double* values, double eps) {
    double tmp, t;
    Reflection(n, a);
    printMatrix(n,a,7);
    for (int k = n; k > 2; k--) {
        for (int i = 1; i < k; i++) {
            if (a[(i - 1) * n + i - 1] != 0) {
                a[i * n + i - 1] = a[i * n + i - 1] / a[(i - 1) * n + i - 1];
                for (int j = i; j < k; j++) {
                    a[i * n + j] -= a[i * n + i - 1] * a[(i - 1) * n + j];
                }
            }
        }
            
        for (int i = 0; i < k; i++) {
            if (i != 0) {
                a[i * n + i - 1] *= a[i * n + i];
            }
            for (int j = i; j < k - 1; j++) {
                a[i * n + j] += a[i * n + j + 1] * a[(j + 1) * n + j];
            }
        }
    }
    
    if (n != 1) {
        t = a[0] + a[n + 1];
        tmp = a[0] * a[n + 1] - a[1] * a[n];
        tmp = sqrt(t * t - 4 * tmp);
        a[0] = 0.5 * (t + tmp);
        a[n + 1] = 0.5 * (t - tmp);
    }
    
    for (int i = 0; i < n; i++) {
        values[i] = a[i * n + i];
    }
}
