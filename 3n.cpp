/* 
Author: Yakeshia Jenkins
Assignment: 3n+1 
Instructions: 
1. input n
2. print n
3. if n = 1 then STOP
4. if n is odd then n <- 3n + 1
5. else n <- n/2 even
6. GOTO 2
c(n) = number of times t(n) will happen */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
using	namespace	std;

int c(int);
const int CACHE_LEN = 1000001;
int cache[CACHE_LEN] = {0}; 

int c(int start)
{
    int length = cache[start];
    if (length != 0) 
    {
      return length;
    }
    
    length++;
    
    int n = start;
    
    while (n != 1) // if n = 1, STOP
    {
        if (n % 2 == 0) //if n is even
        {
          n /= 2;
        } 
        else //if n is odd
          n = 3 * n + 1; 
          
        length++;
    }
    cache[start] = length;
    return length;
}  
  
int main()
{
    int i, j;
	
    //determine the max cycle length for integers b/t and including i and j
    while ( scanf("%d %d", &i, &j) != EOF ) //scanf is faster then cin
    {
        int maxC = 0;
        
         int L = min(i, j);
         int H = max(i, j);
		 
        //Finding the maximum, I referenced old homework assignments from PFII
        for (int k = L; k <= H; ++k )
        {
            int curCycles = c(k);
            if (curCycles > maxC) 
            {
              maxC = curCycles;
            }
        }
        printf("%d %d %d\n", i, j, maxC); //printf is faster then cout
    }
    return 0;
}