/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-12 21:32:53
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-12 21:50:33
 * @LastEditors: Leon-Francis
 * @Description: 动态规划：能量项链
 * @FilePath: /AlgorithmPractice/luogu/P1063.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int weight[101];
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }
    int nums[101][101] = {0};
    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        for (int x = 0; x < N; x++)
        {
            //nums[x][x+i]
            for (int k = 0; k < i; k++)
            {
                //nums[x][x+k] nums[x+k+1][x+i]
                nums[x][(x + i) % N] = max(nums[x][(x + i) % N], nums[x][(x + k) % N] + nums[(x + k + 1) % N][(x + i) % N] + weight[x] * weight[(x + k + 1) % N] * weight[(x + i + 1) % N]);
                ans = max(ans, nums[x][(x + i) % N]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// AC