/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-23 12:16:23
 * @LastEditTime: 2020-09-23 15:58:06
 * @LastEditors: Leon-Francis
 * @Description: 对局匹配
 * @FilePath: /cpp/lanqiao/PREV-50.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;

#if 0
int max_num = 0;

void distribution(vector<pair<int, bool>> nums, int n, int K, int num)
{
    if (num + nums.size() - n < max_num)
    {
        return;
    }
    if (n == nums.size())
    {
        max_num = max(max_num, num);
        return;
    }
    bool res = true;
    for (int i = 0; i < n; i++)
    {
        if (nums[i].second && abs(nums[n].first - nums[i].first) == K)
        {
            res = false;
            break;
        }
    }
    if (res)
    {
        nums[n].second = true;
        distribution(nums, n + 1, K, num + 1);
        nums[n].second = false;
        distribution(nums, n + 1, K, num);
    }
    else
    {
        nums[n].second = false;
        distribution(nums, n + 1, K, num);
    }
}

int main(int argc, char const *argv[])
{
    int N, K;
    cin >> N >> K;
    vector<pair<int, bool>> nums(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i].first;
        nums[i].second = false;
    }
    distribution(nums, 0, K, 0);
    cout << max_num << endl;
    return 0;
}
#endif

int main(int argc, char const *argv[])
{
    int nums[100001] = {};
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums[num]++;
    }
    int ans = 0;
    if (k == 0)
    {
        for (int i = 0; i < 100001; i++)
        {
            if (nums[i] != 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < k; i++)
    {
        vector<int> dp;
        for (int j = i; j < 100001; j += k)
        {
            if ((j - i) / k == 0)
            {
                dp.push_back(nums[j]);
                continue;
            }
            if ((j - i) / k == 1)
            {
                dp.push_back(max(nums[j], dp[(j - i) / k - 1]));
                continue;
            }
            dp.push_back(max(dp[(j - i) / k - 1], dp[(j - i) / k - 2] + nums[j]));
        }
        ans += dp[dp.size() - 1];
        dp.clear();
    }
    cout << ans << endl;
    return 0;
}
