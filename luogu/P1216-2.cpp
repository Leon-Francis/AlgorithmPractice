/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-16 20:24:41
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-16 20:30:08
 * @LastEditors: Leon-Francis
 * @Description: [USACO1.5][IOI1994]数字三角形 Number Triangles
 * @FilePath: /AlgorithmPractice/luogu/P1216-2.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;

int N;
int nums[1001][1001];

int main()
{
    cin >> N;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            nums[i][j] = -1;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> nums[i][j];
        }
    }
    for (int row = 2; row <= N; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            nums[row][col] += max(nums[row - 1][col - 1], nums[row - 1][col]);
        }
    }
    int ans = nums[N][1];
    for (int i = 2; i <= N; i++)
    {
        if (nums[N][i] > ans)
        {
            ans = nums[N][i];
        }
    }
    cout << ans << endl;
    return 0;
}
