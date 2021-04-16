/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-16 19:54:58
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-16 20:11:59
 * @LastEditors: Leon-Francis
 * @Description: 数字三角形解法2
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-58-2.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;

int N;
int nums[101][101];

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
    if (N % 2 != 0)
    {
        cout << nums[N][(N + 1) / 2] << endl;
        return 0;
    }
    else
    {
        cout << max(nums[N][N / 2], nums[N][N / 2 + 1]) << endl;
    }
    return 0;
}
