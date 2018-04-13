/* 
 * File:   shoemaker.cpp
 * Author: YJTHETRUTH
 *
 * Created on February 13, 2018, 10:32 PM
 */

#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define max 1000
/*
 * Kept getting PE : I used this forum to get insight on what the error could be
 * https://uva.onlinejudge.org/board/viewtopic.php?f=5&t=209520
 * 
 * data structure http://www.cplusplus.com/doc/tutorial/structures/
 * Sort http://www.cplusplus.com/reference/algorithm/sort/
 */
struct Node {
    int S, T; //time and fine
    int priority; 
};

struct myclass {
    bool operator() (const Node &a, const Node &b)
    {
        if (a.T * b.S != b.T * a.S)
        {
            return a.T * b.S < b.T * a.S;
        }
        else
            return a.priority < b.priority;
    }
} c;

int main(int argc, char** argv) {
    int job_num; //jobs number  
    int N; //# of cases  
    Node temp[max];
    
    scanf("%d", &N); //read # of test cases
   // printf("\n");
    
    while(N--)
    {  
 
      scanf("%d", &job_num);
          
      for(int i = 0; i < job_num; ++i)
      {
          cin >> temp[i].T >> temp[i].S;
          temp[i].priority = i + 1;
      }

      //sort begin, last, compare for minimal fine
      sort(temp, temp + job_num, c);
      
      //print  the sequence of jobs with minimal fine
      //multiple solutions, print the first lexicographically (alphabetical)
      for(int i = 0; i < job_num; ++i)
      {         
          if(i != job_num-1)
              printf("%d ", temp[i].priority);
          else
              printf("%d\n", temp[i].priority);
      }      
      if(N > 0)
        printf("\n");     
    }
      
    return 0;
}

