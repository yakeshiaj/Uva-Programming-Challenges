/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrimaryArithmetic.cpp
 * Author: YJTHETRUTH
 *
 * Created on February 21, 2018, 7:56 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    long long int a, b; //integers
    
    while(true)
    {
        scanf("%lld%lld", &a, &b);
        if (a == 0 && b ==0)
           return 0;

        long long int carry = 0;
        long long int counter = 0;
        while(a > 0 || b > 0)
        {
            //adding the remainders 
            carry = (((a % 10 + b % 10) + carry) / 10);
            a /= 10;
            b /= 10;
            
            if (carry)
                counter++; //count # of carries
        }
        if (counter == 0)
        {
            printf("No carry operation.\n");
        }
        else if(counter == 1)
        {
            printf("%lld carry operation.\n", counter);
        }
        else
            printf("%lld carry operations.\n", counter);
    }
    return 0;
}

