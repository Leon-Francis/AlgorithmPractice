/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-21 20:51:39
 * @LastEditTime: 2020-09-21 21:39:49
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC_test/Q_2.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
#include <math.h>
using namespace std;

void cul(double v_0, double v, double n, double r, double R, double h, double l)
{
    v_0 += v * n;
    double sum_v = 1.0 / 3.0 * 3.1415926 * h * (R * R + r * r + R * r);
    if (v_0 > sum_v)
    {
        cout << "Overflow!" << endl;
        return;
    }
    if (l >= h)
    {
        cout << "Yeah!" << endl;
        return;
    }
    double x = r * h / (R - r);
    r = r * (x + l) / x;
    h = h - l;
    double able_v = 1.0 / 3.0 * 3.1415926 * h * (R * R + r * r + R * r);
    if (v_0 >= able_v)
    {
        cout << "Yeah!" << endl;
        return;
    }
    int nums = ceil((able_v - v_0) / v);
    cout << "Sorry, " << nums << " stones needed." << endl;
    return;
}

int main(int argc, char const *argv[])
{
    int s;
    cin >> s;
    double **p = new double *[s];
    for (int i = 0; i < s; i++)
    {
        p[i] = new double[7];
        for (int j = 0; j < 7; j++)
        {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < s; i++)
    {

        cul(p[i][0], p[i][1], p[i][2], p[i][3], p[i][4], p[i][5], p[i][6]);
    }
    return 0;
}
