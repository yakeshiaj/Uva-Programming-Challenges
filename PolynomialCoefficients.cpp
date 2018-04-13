/* 
 * File:   PolynomialCoefficients.cpp
 * Author: YJTHETRUTH
 *
 * Created on February 21, 2018, 2:26 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {   
   // N!
    long long int fact[13]; //( N < 13)
    fact[0] = 1;
    for(int i = 1; i < 13; ++i)
        fact[i] = i * fact[i-1]; 
    
    int N, K; //Power of Polynomial && # of variables     
    // calculate the coefficient 
    while (scanf("%d %d", &N, &K) == 2)
    {
       long long int temp = 1;
        for(int i = 0; i < K; ++i)
        {
            long long int n = 1;
            scanf("%lld", &n); //Variables
            temp *= fact[n];
        }
        temp = (fact[N]/temp);
        printf("%lld", temp); //answer
        printf("\n"); 
    }
    return 0;
}

