/* 
 * File:   main.cpp
 * Author: YJTHETRUTH
 *
 * Created on March 6, 2018, 4:16 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

/*
 * http://www.algorithmist.com/index.php/UVa_10110
 */

int main(int argc, char** argv) {
    
    long long n;
    
    while(true)
    {
        scanf("%lld", &n);
        
        if(n == 0) 
            break;
        
        long long toggle = sqrt(n);
        long long tmp = toggle * toggle;
        
    //The answer is yes iff the nth switch is toggled an odd number of times 
        printf("%s\n", tmp == n ? "yes" : "no");
    }

    return 0;
}

