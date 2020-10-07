/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-20 16:39:21
 * @LastEditTime: 2020-09-20 17:33:15
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC/Q_1002.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        nums[i] = a + b;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    return 0;
}
