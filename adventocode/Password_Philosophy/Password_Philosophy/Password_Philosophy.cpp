// Password_Philosophy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
int main()
{
    int tmp = 0;
    string range, letter, password;
    vector<int> expences;
    int wrong_passwords = 0;
    while (cin >> range >> letter >> password)
    {
       string token;
       istringstream tokenStream(range);
       vector<int> range;
       while (getline(tokenStream, token, '-'))
       {
           range.push_back(stoi(token));
       }
       int occurencies = 0;
       for (char i : password) {
           if (i == letter[0])
               occurencies++;
       }
       if (occurencies >= range[0] && occurencies <= range[1])
           wrong_passwords++;

    cout << range[0] << "-" << range[1] << "->" << password<<" ["<<letter[0] <<"]" <<" wrong passords : " << wrong_passwords << endl;
    }

}
*/

int main()
{
    int tmp = 0;
    string range, letter, password;
    vector<int> expences;
    int wrong_passwords = 0;
    while (cin >> range >> letter >> password)
    {
       string token;
       istringstream tokenStream(range);
       vector<int> range;
       while (getline(tokenStream, token, '-'))
       {
           range.push_back(stoi(token));
       }
       int occurencies = 0;
       if (password[range[0] - 1] == letter[0])
           occurencies++;
       if (password[range[1] - 1] == letter[0])
           occurencies++;

       if (occurencies == 1)
           wrong_passwords++;

    cout << range[0] << "-" << range[1] << "->" << password<<" ["<<letter[0] <<"]" <<" wrong passords : " << wrong_passwords << endl;
    }

}
