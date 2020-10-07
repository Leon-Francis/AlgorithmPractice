/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-20 22:53:39
 * @LastEditTime: 2020-09-20 23:35:24
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/lanqiao/ALGO-1.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }
//     int t;
//     cin >> t;
//     int **req;
//     req = new int *[t];
//     for (int i = 0; i < t; i++)
//     {
//         req[i] = new int[3];
//         cin >> req[i][0] >> req[i][1] >> req[i][2];
//     }

//     for (int i = 0; i < t; i++)
//     {
//         delete[] req[i];
//     }
//     delete[] req;
//     return 0;
// }

int k_max(vector<int> nums, int a, int b, int c)
{
    vector<int> temps(nums.begin() + a - 1, nums.begin() + b);
    sort(temps.begin(), temps.end());
    int i = temps.size() - c;
    return temps[i];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << k_max(nums, a, b, c) << endl;
    }
    return 0;
}
