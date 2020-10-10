/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-10-09 21:33:27
 * @LastEditTime: 2020-10-09 21:33:30
 * @LastEditors: Leon-Francis
 * @Description: PREV-48: 数组操作
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-48.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int nums[100000];

int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r, d;
            cin >> l >> r >> d;
            for (int j = l; j <= r; j++)
            {
                nums[j - 1] += d;
            }
        }
        else if (t == 2)
        {
            int temp[100000];
            int l_1, r_1, l_2, r_2;
            cin >> l_1 >> r_1 >> l_2 >> r_2;
            for (int j = 0; j <= r_2 - l_2; j++)
            {
                temp[j] = nums[l_2 + j - 1];
            }
            for (int j = 0; j <= r_1 - l_1; j++)
            {
                nums[l_1 + j - 1] = temp[j];
            }
        }
        else if (t == 3)
        {
            ll sum = 0;
            int l, r;
            cin >> l >> r;
            for (int j = l; j <= r; j++)
            {
                sum += nums[j - 1];
            }
            cout << sum << endl;
        }
    }
    return 0;
}
//超时长了，想想其他解决办法
//没有办法，查不到其他可用思路
