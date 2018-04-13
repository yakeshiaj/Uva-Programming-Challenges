/* 
 * File:   cuttingsticks.cpp
 * Author: YJTHETRUTH
 *
 * Created on April 9, 2018, 9:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

#define max 55

using namespace std;

/*
 * http://www.algorithmist.com/index.php/UVa_10003
 * 
 * http://www.algorithmist.com/index.php/Dynamic_Programming
 * 
 * http://www.cplusplus.com/reference/algorithm/min/
 * 
 * https://stackoverflow.com/questions/17946436/compile-time-warning-about-memset-on-non-plain-old-data
 */
  template <class T> const T& Min (const T& a, const T& b) {
        return ! (b<a) ? a : b;   
  }
int main(int argc, char** argv) {
   
   int l;
    
   while(scanf("%d", &l) && l) //length of stick
   {    
       int n, c[max], ct[max][max];
       
       if (l == 0) //end of stick
           break;

       scanf("%d", &n); //# of cuts
       
       //0 < ci < l
       c[0] = 0;
       c[n + 1] = l;
       for (int i = 1; i <= n; i++) 
           scanf("%d", &c[i]);
        //solve
       for(int j = 0;j <= n; j++) 
            ct[j][j+1] = 0;
       
       int best;
        for (int right = 2; right <= n+1; right++) 
          for (int left = right - 2; left >= 0; left--)
            {                     
                best = 2e9;
                for(int i = left + 1; i < right; i++)
                    best = Min(best,(ct[left][i]+ct[i][right]+c[right]-c[left]));
                ct[left][right] = best;
          }
       printf("The minimum cutting is %d.\n", ct[0][n+1]);   
    }
    return 0;
}

