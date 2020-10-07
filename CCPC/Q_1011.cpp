/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-20 21:17:10
 * @LastEditTime: 2020-09-20 21:21:43
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC/Q_1011.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include<iostream>
using namespace std;

void D2H(int n)
{
    if(n > 0)
    {
        D2H(n / 8);
        cout << n % 8;
    }
    else
    {
        return;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    D2H(n);
    return 0;
}

