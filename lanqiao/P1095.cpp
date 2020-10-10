/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-10-10 20:57:13
 * @LastEditTime: 2020-10-10 20:57:16
 * @LastEditors: Leon-Francis
 * @Description: P1095 守望者的逃离
 * @FilePath: /AlgorithmPractice/lanqiao/P1095.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int m, s, t;
    cin >> m >> s >> t;
    vector<int> dp(t + 1);
    dp[0] = 0;
    for (int i = 1; i <= t; i++)
    {
        if (m >= 10)
        {
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        }
        else
        {
            m += 4;
            dp[i] = dp[i - 1];
        }
    }
    int i;
    for (i = 1; i <= t; i++)
    {
        dp[i] = max(dp[i], dp[i - 1] + 17);
        if (dp[i] >= s)
        {
            cout << "Yes" << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    cout << dp[i-1] << endl;
    return 0;
}
//这个题的思路很新奇，以后可以多做参考※※※※※※※※※※※
