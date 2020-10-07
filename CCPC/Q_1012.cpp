/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-20 21:25:33
 * @LastEditTime: 2020-09-20 21:31:21
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC/Q_1012.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
using namespace std;

int fcb(int a, int b, int n)
{
    if (n == 1)
    {
        return a;
    }
    else if (n == 2)
    {
        return b;
    }
    else if (n % 2 == 1)
    {
        return fcb(a, b, n - 1) + fcb(a, b, n - 2);
    }
    else
    {
        return fcb(a, b, n - 1) + fcb(a, b, n - 2) + fcb(a, b, n - 3);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        cout << fcb(a, b, t) << endl;
    }
    return 0;
}
