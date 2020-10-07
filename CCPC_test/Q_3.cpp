/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-21 20:13:22
 * @LastEditTime: 2020-09-21 21:45:26
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC_test/Q_3.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    int n;
    cin >> n;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            int temp = (str[i] - 'a' + n) % 26;
            str[i] = temp + 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            int temp = (str[i] - 'A' + n) % 26;
            str[i] = temp + 'A';
        }
    }
    cout << str << endl;
    return 0;
}
