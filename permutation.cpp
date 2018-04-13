/* 
 * File:   permutation.cpp
 * Author: YJTHETRUTH
 *
 * Created on February 4, 2018, 9:37 PM
 */
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

/*
 * 
 */
void CheckNumLetters(int counter[], const string &l)
{
    for(int i = 0; i < l.length(); i++)
        {
            counter[(int)(l[i]-'a')]++;
        }
}

int main(int argc, char** argv) {
 
    string a, b; //two strings of lowercase letters
  //  string x; //longest string of lowercase letters
    
    while (getline(cin,a))
    {
         getline(cin,b);        
        int Count_a[26] = {0}, Count_b[26] = {0};            
//Get # of Letters from string a, b
        CheckNumLetters(Count_a, a);
        CheckNumLetters(Count_b, b);
         
        for(int j = 0; j < 26; j++)
        {
            //Get the min(x,y) time in c            
            int temp = min(Count_a[j], Count_b[j]);            
            for (int k = 0; k < temp; k++)
            {
                cout << (char)(j + 'a');
            }
        }
        cout << endl;
    }
    
    return 0;
}

