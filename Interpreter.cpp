/* 
 * File:   Interpreter.cpp
 * Author: YJTHETRUTH
 *
 * Created on April 3, 2018, 5:28 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX_RAM 1000 //1000 word
#define MAX_REG 10   //10 registers
using namespace std;

/*
 * https://uva.onlinejudge.org/board/viewtopic.php?f=9&t=13985
 * https://uva.onlinejudge.org/board/viewtopic.php?t=13985&start=15
 */

int interpreter(int RAM[])
{
    int REG[MAX_REG] = {0};
    int halt = 0;
    int addr = 0;
    int i;
    for(i = 0; !halt; ++i)
    {
        int temp = RAM[addr];
        int d = temp %100/10; 
        int n = temp %10;   
        int s = temp /100;
        ++addr;
        addr %= 1000;
        
        //encodings 
        switch(s)
        {
            // 100 means halt
            case 1: 
                halt = 1;
                break;
            // 2dn means set register d to n (between 0 and 9)
            case 2:
                REG[d] = n;
                break;
            //  3dn means add n to register d  
            case 3:
                REG[d] += n;
                REG[d] %= 1000;
                break;
                //4dn means multiply register d by n
            case 4:
                REG[d] *= n;
                REG[d] %= 1000;
                break;            
                //5ds means set register d to the value of register s
            case 5:
                REG[d] = REG[n];
                break;           
                //6ds means add the value of register s to register d
            case 6:
                REG[d] += REG[n];
                REG[d] %= 1000;
                break;
                // 7ds means multiply register d by the value of register s
            case 7:
                REG[d] *= REG[n];
                REG[d] %= 1000;
                break;
                //8da means set register d to the value in RAM whose address is in register a
            case 8:
                REG[d] = RAM[REG[n]];
                break;
                //9sa means set the value in RAM whose address is in register a to the value of register s
            case 9:
                RAM[REG[n]] = REG[d];
                break;
                //0ds means goto the location in register d unless register s contains 0
            case 0:
                if(REG[n] != 0)
                    addr = REG[d];
                break;
            default:
                break;
        }
    }
    return i;
}
int main(int argc, char** argv) {
    int tc; //test cases
    scanf("%d\n", &tc);
    
    while(tc--)
    {
        int RAM[MAX_RAM] = {};       
        char buff[10];
        int addr = 0;

        //Convert string to int        
        while(fgets(buff, 10, stdin) != NULL && buff[0] != '\n')
            RAM[addr++] = atoi(buff);
        //calls the interpreter function         
        printf("%d\n", interpreter(RAM));
        
        if (tc > 0)
            cout << endl;
    }
    
    return 0;
}

