/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-20 20:17:46
 * @LastEditTime: 2020-09-20 20:27:43
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC/Q_1007.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include<iostream>
#include<iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
    int nums[20];
    for (int i = 0; i < 20; i++)
    {
        cin >> nums[i];
    }
    double avg = 0;
    int pos_count = 0;
    int neg_count = 0;
    for (int i = 0; i < 20; i++)
    {
        if(nums[i] < 0)
        {
            neg_count++;
        }
        else if(nums[i] > 0)
        {
            pos_count++;
            avg += nums[i];
        }
    }
    avg = avg / pos_count;
    cout << neg_count << endl;
    cout << fixed << setprecision(2) << avg << endl;
    return 0;
}
