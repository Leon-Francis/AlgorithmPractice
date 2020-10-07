/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-23 10:52:58
 * @LastEditTime: 2020-09-23 11:13:31
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/lanqiao/PREV-52.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b;
    int n;
    cin >> a >> b >> n;
    a = a % b;
    for (int i = 1; i < n; i++)
    {
        a *= 10;
        a = a % b;
    }
    for (int i = 0; i < 3; i++)
    {
        a *= 10;
        cout << a / b;
        a = a % b;
    }
    cout << endl;
    return 0;
}
