/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-20 20:27:30
 * @LastEditTime: 2020-09-20 20:32:56
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC/Q_1008.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
using namespace std;

int gcb(int a, int b)
{
    int c = a % b;
    if (c == 0)
    {
        return b;
    }
    else
    {
        return gcb(b, c);
    }
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    cout << gcb(a, b) << endl;
    cout << a * b / gcb(a, b) << endl;
    return 0;
}
