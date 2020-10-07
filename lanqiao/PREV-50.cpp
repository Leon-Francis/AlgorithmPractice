/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-23 12:16:23
 * @LastEditTime: 2020-09-23 15:58:06
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/lanqiao/PREV-50.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;

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
