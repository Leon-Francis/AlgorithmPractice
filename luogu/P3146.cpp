/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-12 20:52:56
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-12 21:23:48
 * @LastEditors: Leon-Francis
 * @Description: 动态规划：248 G
 * @FilePath: /AlgorithmPractice/luogu/P3146.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int nums[249][249] = {0}; //nums[i][j]代表从i到j能完全合并的最大数值
    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i][i];
    }
    int ans = 0;
    for (int i = 1; i < N; i++) // 跨度
    {
        for (int j = 1; j + i <= N; j++) // 初始位置
        {
            // nums[j][j+i]
            for (int pos = 0; pos < i; pos++)
            {
                //nums[j][j+pos] nums[j+pos+1][j+i]
                if ((nums[j][j + pos] == nums[j + pos + 1][j + i]) && nums[j][j + pos] != 0)
                {
                    nums[j][j + i] = max(nums[j][j + i], nums[j][j + pos] + 1);
                    ans = max(ans, nums[j][j + pos] + 1);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// AC