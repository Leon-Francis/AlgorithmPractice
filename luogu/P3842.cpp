/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-10-12 21:22:51
 * @LastEditTime: 2020-10-12 21:23:51
 * @LastEditors: Leon-Francis
 * @Description: P3842 线段
 * @FilePath: /AlgorithmPractice/lanqiao/P3842.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int dp[100001][2];
    int n;
    cin >> n;
    vector<vector<int>> linear(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        linear[i].push_back(a);
        linear[i].push_back(b);
    }
    dp[0][0] = linear[0][1] + linear[0][1] - linear[0][0] - 1;
    dp[0][1] = linear[0][1] - 1;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + abs(linear[i - 1][0] - linear[i][1]) + linear[i][1] - linear[i][0] + 1,
                       dp[i - 1][1] + abs(linear[i - 1][1] - linear[i][1]) + linear[i][1] - linear[i][0] + 1);
        dp[i][1] = min(dp[i - 1][0] + abs(linear[i - 1][0] - linear[i][0]) + linear[i][1] - linear[i][0] + 1,
                       dp[i - 1][1] + abs(linear[i - 1][1] - linear[i][0]) + linear[i][1] - linear[i][0] + 1);
    }
    cout << min(dp[n - 1][0] + n - linear[n - 1][0], dp[n - 1][1] + n - linear[n - 1][1]) << endl;
    return 0;
}
//bingo
