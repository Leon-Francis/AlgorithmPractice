/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-10-10 21:58:00
 * @LastEditTime: 2020-10-10 21:58:05
 * @LastEditors: Leon-Francis
 * @Description: P1077 摆花
 * @FilePath: /AlgorithmPractice/lanqiao/P1077.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int a[101];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int dp[101][101];
    for (int i = 0; i <= m; i++)
    {
        if (i > a[n])
        {
            dp[n][i] = 0;
        }
        else
        {
            dp[n][i] = 1;
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
            for (int k = 0; k <= a[i] && j - k >= 0; k++)
            {
                dp[i][j] += dp[i + 1][j - k];
                dp[i][j] = dp[i][j] % 1000007;
            }
        }
    }
    cout << dp[1][m] % 1000007 << endl;
    return 0;
}
//Yeah!!

