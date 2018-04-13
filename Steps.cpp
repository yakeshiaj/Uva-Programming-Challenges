/* 
 * File:   Steps.cpp
 * Author: YJTHETRUTH
 *
 * Created on February 25, 2018, 08:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

/*
 * http://www.algorithmist.com/index.php/UVa_846
 */
int main(int argc, char** argv) {

    int n;    
    int x, y;
    int diff, mSteps, output;
    bool Increase;
 
    scanf("%d", &n); //# of test cases
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y); // 0 ≤ x ≤ y < 2^31

        diff = y - x;
        mSteps = 1; //Skip the start number due to the fact is always 0
        output = 0;
        Increase = false;
            
        while(diff > 0)
        {
            diff = diff - mSteps;
            output++;
            
            if(Increase == true)
                mSteps++;
            
            Increase = !Increase;
        }
        
        printf("%d\n", output); //min # of steps x to y
    }
    return 0;
}

