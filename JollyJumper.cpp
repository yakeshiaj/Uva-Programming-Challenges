/*A sequence of n > 0 integers is called jolly jumpers, if the absolute values of the difference between successive elements take 
 * on all the values 1 through n - 1. For instance, 1 4 2 3 is a jolly jumper, because the absolute differences are 3, 2, and 1. 
 * That any sequence of a single integer is a jolly jumper. 
 * 2 5 1 3 4 
 * |2-5| = 3, |5-1| = 4, |1-3| = 2, |3-4| = 1
 * The sequence(n) number cannot be 0
 * The sequence(n) number cannot be equal or greater than the input(numbers in my code). 
 * If there are 4 numbers then the sequence should contain the numbers 1,2,3
 * There cannot be duplicates.
 */

/* 
 * File: JollyJumper.cpp
 * Author: YJTHETRUTH
 *Created on January 26, 2018, 6:27 PM
 */

#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define max 3001

using namespace std;

/*
 * http://www.algorithmist.com/index.php/UVa_10038
 */
int main(int argc, char** argv) {
    
   int n, i;
   int sequenceNum[max];
   int diff[max];
   bool found; 
   
   while(scanf("%d", &n) != EOF) 
    {          
       found = true;
       for(i = 0; i < n; i++){      
           scanf("%d", &sequenceNum[i]);  
       }
      for(i = 0; i < n - 1; i++){
    //the difference between successive elements take on all the values 1 through n - 1    
         diff[i] = abs(sequenceNum[i+1] - sequenceNum[i]);
      }
       sort(diff, diff+i);
    
       for(i = 1; i < n; i++){
           if(diff[i] == diff[i-1])
           {
               found = false;
               break;
           }
        } 
       if(found == false){
           printf("Not jolly\n");
       }
       else{
            printf("Jolly\n");
       }
   }
   return 0; 
}

