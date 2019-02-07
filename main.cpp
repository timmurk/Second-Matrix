#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "input.h"
#include "matrix.h"

#define v_size 5

using namespace std;

int main() {
    
    int n, res, c;
    double eps = 1e-9;
    double trace, norm;
    double *a, *e_val;
    clock_t ft, et;
    FILE *in;
    
    cout << "Type of insert : \n 1 - file \n 2 - formula \n other letters are invalid \n";
    
    cin >> c;
    if (c == 1) {
        in = fopen("a.txt","r");
        if (!in) {
            cout << "Open fault \n";
            return -1;
        }
        if (fscanf(in,"%d",&n) != 1) {
            cout << "There is a trash in file \n";
            fclose(in);
            return -1;
        }
    } else if (c == 2) {
        cout << "Choose your n \n";
        cin >> n;
    } else {
        cout << "Invalid insert \n" << c;
        return -1;
    }
    
    if (n < 1) {
        cout << "Invalid n \n";
        return -1;
    }
    
    a = (double*)malloc(n*n*sizeof(double));
    e_val =(double*)malloc(n*sizeof(double));
    
    if (!a || !e_val) {
        if (c == '1') {
            fclose(in);
        }
        free(a);
        free(e_val);
        cout << "Fault of array \n";
        return -1;
    }
    
    res = inputMatrix(c,in,n,a,e_val);
    
    if (res == -1) {
        free(a);
        free(e_val);
        fclose(in);
        cerr << "Some problem \n";
        return -1;
    }
    cout << n << endl;
    cout << "First " << min(v_size,n)    << " minor of matrix : \n";
    //printMatrix(n,a,v_size);
    
    trace = checkTrace(a,n,0);
    norm = checkNorm(a,n,0);
    
    printMatrix(n,a,v_size);
    ft = clock();
    eigValues(n,a,e_val,eps);
    et = clock();
    
    trace += checkTrace(e_val,n,1);
    norm -= checkNorm(e_val,n,1);
    
    cout << "Eigen values : \n" ;
    printEVal(n,e_val,v_size);
    cout << endl;
    
    cout << "\n Check norms. \n";
    
    cout << "Trace norm is : \n";
    cout <<fabs(trace);
                
    cout << "\n Matrix norm is : \n" ;
    cout << fabs(norm);
    
    cout << "\n Time of working \n" << (double)(et-ft)/CLOCKS_PER_SEC;
    cout << endl;
    
    fclose(in);
    free(a);
    free(e_val);
    return 0;
}

