/* 
 * File:   Vito.cpp
 * Author: YJTHETRUTH
 *
 * Created on February 13, 2018, 7:33 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
/*
 * Sort http://www.cplusplus.com/reference/algorithm/sort/
 * 
 * Kept getting WA, used this forum for insight
 * https://uva.onlinejudge.org/board/viewtopic.php?f=9&t=37104&hilit=Vito&start=15#p18378
 */
int main(int argc, char** argv) {
    int cases;       
    int s[30000]; //max 30000
    int tmp;
    int r; //max 500
    
    scanf("%d", &cases); //# of test cases
    while (cases--) //decrement the test cases
    {
        scanf("%d", &r); //# of relatives
        
        for(int i = 0; i < r; i++)
        {
            scanf("%d", &s[i]); //street #
        }
        sort(s, s+r); //sort the first street # and last street # in ascending order (small to high)
        tmp = s[r/2]; //median of of the values
        
        int distance = 0;        
        for(int j = 0; j < r; j++)
        {
            distance += abs(tmp-s[j]); // distance(ij)  = |si - sj|
        }
        printf("%d\n", distance);
    }    
    return 0;
}

