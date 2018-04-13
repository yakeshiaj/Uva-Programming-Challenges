/* 
 * File:   WERTY.cpp
 * Author: YJTHETRUTH
 *
 * Created on February 3, 2018, 10:46 PM
 */

#include <cstdlib>
#include <map>
#include <cstdio>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char input;
    map<const char, char> KEYS; //mapped keys
    
//First row of keys    
    KEYS['1'] =  '`';
    KEYS['2'] =  '1';
    KEYS['3'] =  '2';
    KEYS['4'] =  '3';
    KEYS['5'] =  '4';
    KEYS['6'] =  '5';
    KEYS['7'] =  '6';
    KEYS['8'] =  '7';
    KEYS['9'] =  '8';
    KEYS['0'] =  '9';
    KEYS['-'] =  '0';
    KEYS['='] =  '-';
//Second row of keys       
    KEYS['W'] =  'Q';
    KEYS['E'] =  'W';
    KEYS['R'] =  'E';
    KEYS['T'] =  'R';
    KEYS['Y'] =  'T';
    KEYS['U'] =  'Y';
    KEYS['I'] =  'U';
    KEYS['O'] =  'I';
    KEYS['P'] =  'O';
    KEYS['['] =  'P';
    KEYS[']'] =  '[';
    KEYS['\\'] = ']';
//Third row of keys       
    KEYS['S'] = 'A';
    KEYS['D'] = 'S';
    KEYS['F'] = 'D';
    KEYS['G'] = 'F';
    KEYS['H'] = 'G';
    KEYS['J'] = 'H';
    KEYS['K'] = 'J';
    KEYS['L'] = 'K';
    KEYS[';'] = 'L';
    KEYS['\''] = ';';
//Fourth row of keys       
    KEYS['X'] =  'Z';
    KEYS['C'] =  'X';
    KEYS['V'] =  'C';
    KEYS['B'] =  'V';
    KEYS['N'] =  'B';
    KEYS['M'] =  'N';
    KEYS[','] =  'M';
    KEYS['.'] =  ',';
    KEYS['/'] =  '.';
//space Echoed    
    KEYS[' '] =  ' ';        
    KEYS['\n'] = '\n';
    
    while ((input = getchar()) != EOF) //returns the next character
    {
        putchar(KEYS[input]); //writes character
    }
    return 0;
}