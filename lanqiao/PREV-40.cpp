/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-16 21:22:44
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-17 21:03:28
 * @LastEditors: Leon-Francis
 * @Description: K倍区间(前缀和)
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-40.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;

int N, K;
int nums[100001];
int sum[100001] = {0};
int cnt[100001] = {0};

int main()
{
    cin >> N >> K;
    sum[0] = 0;
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i];
        sum[i] = (sum[i - 1] + nums[i]) % K;
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    cout << ans + cnt[0] << endl;
    return 0;
}