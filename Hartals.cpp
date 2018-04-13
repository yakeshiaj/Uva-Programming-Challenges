/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YJTHETRUTH
 *
 * Created on January 30, 2018, 3:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>


using namespace std;

/* One of the parameters is a positive integer h (called the hartal parameter) 
 * that denotes the average number of days between two successive hartals (strikes) called by the corresponding party. 
 * Though the parameter is far too simple to be flawless, it can still be used to 
 * forecast the damages caused by hartals.
 * In this problem, given the hartal parameters for several political parties and the value of N, your
 * job is to determine the number of working days we lose in those N days.
 */
int main(int argc, char** argv) {
    
    //N(7 <= N <= 3650) # of days
    //P(1 <= P <= 100) # of politcial parties
    //i(1<= i <= P) hartal parameter *h(i) will never be a multiple of 7

    int T = 0; //#ofTestCases
    int N = 0; //#ofdays
    int P = 0; //#ofpoliticalparties
    
    
    scanf("%d", &T); //get # of Test cases
    
    int * temp = new int[T]; //allocating int temp, set to T
    for(int i = 0; i < T; i++)
    {
        scanf("%d", &N); //get # of days
        scanf("%d", &P); //get # of parties
        
        int h[100]; 
        for(int i = 0; i < P; i++) //hartal parameter for party i
        {    
            scanf("%d", &h[i]);
        } 
        int tmp = 0; 
        for (int k = 1; k <= N; k++)
        {  
            if (k%7 == 6 || k%7 == 0)
            {   
                continue;    
            }            
            for(int l = 0; l < P; l++)
                {                                
                    if(k%h[l] == 0)
                    { 
                        tmp++;
                        break;
                    }                    
                }      
        }
     temp[i] = tmp;
    }
    
    for(int x = 0; x < T; x++)
        cout << temp[x] << endl;
    
    return 0;
}

