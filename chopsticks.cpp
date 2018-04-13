/* 
 * File:   chopsticks.cpp
 * Author: YJTHETRUTH
 *
 * Created on April 11, 2018, 12:44 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

#define max 5005

using namespace std;

/*
 * https://uva.onlinejudge.org/board/viewtopic.php?t=898
 * 
 * http://www.algorithmist.com/index.php/Dynamic_Programming
 * 
 * http://www.cplusplus.com/reference/algorithm/min/
 */
 template <class T> const T& Min (const T& a, const T& b) {
        return ! (b<a) ? a : b;   
  }
int main(int argc, char** argv) {
    
    int T;
    //#of test cases
    scanf("%d\n", &T); 
    
    while(T--)
    {            
        int K, N;
        //# of quests && # of chopsticks
        scanf("%d %d\n", &K, &N); 
        
        int L[max];        
        L[0]=0;
        
        //A, B, C (A ≤ B ≤ C), (A − B)^2
        int badness[max];
        int A = 0, B = 0;       
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A);
            badness[i] = (A-B)*(A-B);
            B = A;
            L[i] = 0;
        }\
        //K + 8 sets, so that the total badness of all the sets is minimized
        K += 8;
        //(0 ≤ K ≤ 1000, 3K + 24 ≤ N ≤ 5000
        int j;
        for (int i = 1; i <= K; i++) { 
            
            for (j = (N-3*(K-i)-1); j >= 2*i; j--)
                L[j] = L[j-2]+badness[j];
            
            for(j += 2; j <= (N-3*(K-i)-1); j++)
                L[j] = Min(L[j],L[j-1]);
            
            L[N-3*(K-i)] = L[N-3*(K-i)-1];
        }
        printf("%d\n", L[N]);
    }
    return 0;
}

