/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-20 20:35:08
 * @LastEditTime: 2020-09-20 20:57:06
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC/Q_1009.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    int letter = 0;
    int digit = 0;
    int square = 0;
    int other = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            letter++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digit++;
        }
        else if (str[i] == ' ')
        {
            square++;
        }
        else
        {
            other++;
        }
    }
    cout << letter << endl;
    cout << square << endl;
    cout << digit << endl;
    cout << other << endl;
    return 0;
}
