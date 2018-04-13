/* 
*Author: Yakeshia Jenkins
*Assignment: The Trip 
*Instructions: 
*Your job is to compute, from a list of expenses, the minimum amount of
*money that must change hands in order to equalize (within a cent) all the students costs.
*/
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <iostream>
using	namespace std;

#define STU 1000 //no more than 1000 students
#define T_max 100000 //no student spend more than $10,000.00

/*
 * http://techualization.blogspot.com/2011/08/problem-10137-trip.html 
 * 
 * http://algorithmist.com/index.php/UVa_10137
 */
int main(int argc, char** argv) {
    int n; 
    int x[STU]; //array for the list of money spent
    
//gathering number of students and money spent
    while (scanf("%d", &n) == 1 && n != 0)
    {
        int total = 0;      

        for (int i = 0; i < n; i++)
        {     
            int D, C; //dollar and cents 
            scanf("%d.%d", &D, &C);
            x[i] = D * 100 + C;
            total += x[i];
        }
//Sort and Equalize the total amount of money spent that must be exchanged  
        int avg = total/n;
        int upper = (avg + ((total % n) ? 1 : 0));
        int most = 0, least = 0;
        
        for(int k = 0; k < n; k++)
        {
            if (x[k] > upper)
                most += (x[k]- upper);
            else if (x[k] < avg)
                least += (avg - x[k]);
        }
        
        int result = max(most, least);
//print out the results        
        printf("$%d.", result / 100);
        
        if(result % 100 < 10)
            printf("0");
        printf("%d\n", result % 100);
    }
    return 0;
}
