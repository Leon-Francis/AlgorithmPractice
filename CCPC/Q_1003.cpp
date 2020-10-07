/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-20 17:34:44
 * @LastEditTime: 2020-09-20 17:39:02
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC/Q_1003.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> nums;
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            break;
        }
        nums.push_back(a + b);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    return 0;
}
