/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-21 20:05:26
 * @LastEditTime: 2020-09-21 20:12:05
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC_test/Q_1.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include<iostream>
#include<iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
    double num;
    cin >> num;
    double result;
    if(num >= 0)
    {
        result = num + 3;
    }
    else
    {
        result = num - 2;
    }
    if(result == int(result))
    {
        cout << "f = " << int(result) << endl;
    }
    else
    {
        cout << "f = " << fixed << setprecision(2) << result << endl;
    }
    return 0;
}
