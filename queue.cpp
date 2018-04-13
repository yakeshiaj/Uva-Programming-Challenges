/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue.cpp
 * Author: YJTHETRUTH
 *
 * Created on March 27, 2018, 8:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#define size 15
using namespace std;
/*
 * memset 
 * http://www.cplusplus.com/reference/cstring/memset/
 * 
 * https://uva.onlinejudge.org/board/viewtopic.php?t=3963#p215582
 */
int main(int argc, char** argv) {
            
    //test cases, # of people in queue,permutations, end
    int T, N, P, R; 
    int table[size][size][size];
    
    memset(table, 0, sizeof(table));
    table[1][1][1] = 1;
    int temp;
    
    for(int i = 1, temp = 13; i <= temp; ++i)
    {
        for(int j = 1, temp = i; j <= temp; ++j)
        {
          for(int k = 1, temp = i; k <= temp; ++k)
          {
              if (table[i][j][k])
              {
                  table[i+1][j+1][k] += table[i][j][k];
                  table[i+1][j][k+1] += table[i][j][k];
                  table[i+1][j][k] += (i-1)*table[i][j][k];
              }
          }
        }
    }
    
    scanf("%d", &T); //get the number of test cases
    while (T--)
    {
        scanf("%d%d%d", &N, &P, &R); //#ofpeople, Permutations (begin), end
        
        printf("%d\n", table[N][P][R]); 
    }

    return 0;
}

