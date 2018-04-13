/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ones.cpp
 * Author: YJTHETRUTH
 *
 * Created on February 21, 2018, 9:47 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
/*
 * 0 <= n <= 10000
 * not divisble of 2 or 5
 * How many digits are in the smallest such a multiple of n?
 * 
 * output: x > 0 such that p = ∑x−1,i=0 1×10^i = a×b, where a is the
 * corresponding input integer, and b is an integer
 * greater than zero.
 */
int main(int argc, char** argv) {
    
    long long int n;
    
    while (scanf("%lld",&n) == 1)
    {
        int ndigits = 1;
        int mod = 1 % n;
        
        //p = ∑x−1,i=0 1×10 i = a×b
        do
        {
            ++ndigits;
            mod = (((mod * 10) + 1) % n);           
        } while(mod);
        
        printf("%d", ndigits);
        printf("\n");
    }

    return 0;
}

