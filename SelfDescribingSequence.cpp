/* 
 * File: SelfDescribingSequence.cpp
 * Author: YJTHETRUTH
 *
 * Created on February 28, 2018, 9:45 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

#define max 2000000000
#define K 700000 // the first 700000 values of f(n)
int g[K] = {0, 1, 3}; //g[i] = array used to store the values
/*
 * https://oeis.org/A001462
 * a(n) = # of times n occurs
 * http://www.cplusplus.com/reference/algorithm/lower_bound/
 * 
 * Was getting a compiler error, I fixed it.
 * http://uva.onlinejudge.org/board/viewtopic.php?f=9&t=3446&hilit=10049&start=30
 */

void SolomonGolomb() //Sequence Value

{    
    //g[2] = 3 && between the first and last, returns the lower bound of i in the range
    for(int i = 3; i < K; ++i)
        g[i] = g[i-1] + lower_bound(g + 1, g + i, i) - g; //g(n) = g(n-1) + (i + 1) 
    
}
int main(int argc, char** argv) {
    int n;   
    
    SolomonGolomb();
    
    while (scanf("%d", &n) && n != 0)
        cout << lower_bound(g + 1, g + K, n) - g << endl;

    return 0;
}

