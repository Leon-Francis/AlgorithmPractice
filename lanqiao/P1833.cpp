/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-10-13 11:54:45
 * @LastEditTime: 2020-10-13 11:54:47
 * @LastEditors: Leon-Francis
 * @Description: P1833 樱花
 * @FilePath: /AlgorithmPractice/lanqiao/P1833.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#if 0
#include <bits/stdc++.h>
using namespace std;
int dp[10001][1001];
int main(int argc, char const *argv[])
{
    string time1;
    string time2;
    cin >> time1 >> time2;
    int n;
    cin >> n;
    int time1_hour = 0;
    int time1_min = 0;
    int time2_hour = 0;
    int time2_min = 0;
    int index;
    for (index = 0; time1[index] != ':'; index++)
    {
        time1_hour = time1_hour * 10 + time1[index] - '0';
    }
    for (index++; index < time1.length(); index++)
    {
        time1_min = time1_min * 10 + time1[index] - '0';
    }
    for (index = 0; time2[index] != ':'; index++)
    {
        time2_hour = time2_hour * 10 + time2[index] - '0';
    }
    for (index++; index < time2.length(); index++)
    {
        time2_min = time2_min * 10 + time2[index] - '0';
    }
    int time = (time2_hour - time1_hour) * 60 + (time2_min - time1_min);
    vector<vector<int>> nums(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int a;
            cin >> a;
            nums[i].push_back(a);
        }
    }
    for (int i = 0; i <= time; ++i)
    {
        int times = i / nums[n][0];
        if (times <= nums[n][2] || nums[n][2] == 0)
        {
            dp[n][i] = times * nums[n][1];
        }
    }
    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = time; j >= 0; --j)
        {
            dp[i][j] = dp[i + 1][j];
            for (int t = 1; j - t * nums[i][0] >= 0 && (t <= nums[i][2] || nums[i][2] == 0); ++t)
            {
                int temp = t * nums[i][1] + dp[i + 1][j - t * nums[i][0]];
                if (dp[i][j] < temp)
                {
                    dp[i][j] = temp;
                }
            }
        }
    }
    cout << dp[1][time] << endl;
    return 0;
}
#endif
// 只有80pts, 最后两个测试点TLE了，答案的方法是用二进制拆分：
#include <algorithm>
#include <cstdio>
#define re register int
using namespace std;
int nx, ny, ex, ey, n, f[1010];
int a[10005], b[10005], c[10005];
int tp, co[1000005], v[1000005]; //尽可能开大，不要把空间开爆了
inline void pre()
{
    for (re i = 1; i <= n; i++)
    {
        int t = 1;
        while (c[i])
        {
            co[++tp] = t * a[i];
            v[tp] = t * b[i];
            c[i] -= t;
            t *= 2;
            if (c[i] < t)
            { //如果剩下的不能再拆，就直接放在一起
                co[++tp] = a[i] * c[i];
                v[tp] = b[i] * c[i];
                break;
            }
        }
    }
}
int main()
{
    scanf("%d:%d%d:%d%d", &nx, &ny, &ex, &ey, &n);
    int t = (ex * 60 + ey) - (nx * 60 + ny);
    for (re i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        if (!c[i])
            c[i] = 999999;
    }
    pre(); //二进制拆分
    for (re i = 1; i <= tp; i++)
    {                                   //考虑每个拆出来的物品
        for (re j = t; j >= co[i]; j--) //01背包板子
            f[j] = max(f[j], f[j - co[i]] + v[i]);
    }
    printf("%d", f[t]);
    return 0;
}