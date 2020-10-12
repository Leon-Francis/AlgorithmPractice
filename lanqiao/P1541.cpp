/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-10-12 22:12:37
 * @LastEditTime: 2020-10-12 22:12:39
 * @LastEditors: Leon-Francis
 * @Description: P1541 乌龟棋
 * @FilePath: /AlgorithmPractice/lanqiao/P1541.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;
// #if 0
// int main(int argc, char const *argv[])
// {
//     int n, m;
//     cin >> n >> m;
//     int dp[351][5] = {0};
//     vector<int> score(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> score[i];
//     }
//     dp[0][0] = score[0];
//     for (int i = 0; i < m; i++)
//     {
//         int a;
//         cin >> a;
//         dp[0][a]++;
//     }
//     for (int i = 1; i < n; i++)
//     {
//         int index = 0;
//         for (int j = 1; j <= 4; j++)
//         {
//             if (i - j >= 0 && dp[i - j][j] > 0)
//             {
//                 if (dp[i][0] < dp[i - j][0])
//                 {
//                     dp[i][0] = dp[i - j][0];
//                     index = j;
//                 }
//             }
//         }
//         if (index != 0)
//         {
//             dp[i][1] = dp[i - index][1];
//             dp[i][2] = dp[i - index][2];
//             dp[i][3] = dp[i - index][3];
//             dp[i][4] = dp[i - index][4];
//             dp[i][index]--;
//             dp[i][0] += score[i];
//         }
//     }
//     cout << dp[n - 1][0] << endl;
//     return 0;
// }
// #endif
int dp[41][41][41][41];
int n, m;
int score[351];
int card[5] = {0, 0, 0, 0, 0};
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int a;
        cin >> a;
        card[a]++;
    }
    dp[0][0][0][0] = score[1];
    for (int a = 0; a <= card[1]; a++)
        for (int b = 0; b <= card[2]; b++)
            for (int c = 0; c <= card[3]; c++)
                for (int d = 0; d <= card[4]; d++)
                {
                    int r = 1 + a + b * 2 + c * 3 + d * 4;
                    if (a != 0)
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + score[r]);
                    if (b != 0)
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + score[r]);
                    if (c != 0)
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + score[r]);
                    if (d != 0)
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + score[r]);
                }
    cout << dp[card[1]][card[2]][card[3]][card[4]] << endl;
    return 0;
}
