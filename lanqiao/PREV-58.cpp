/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-16 19:31:27
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-16 19:48:34
 * @LastEditors: Leon-Francis
 * @Description: 数字三角形
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-58.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;

int N;
int nums[101][101];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            nums[i][j] = -1;
        }
        for (int j = 0; j < i + 1; j++)
        {
            cin >> nums[i][j];
        }
    }
    if (N % 2 != 0)
    {
        for (int i = 0; i < N; i++)
        {
            if (i != (N / 2))
            {
                nums[N - 1][i] = -1;
            }
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if ((i != (N / 2)) && (i != (N / 2 + 1)))
            {
                nums[N - 1][i] = -1;
            }
        }
    }
    for (int row = N - 2; row >= 0; row--)
    {
        for (int col = 0; col <= row; col++)
        {
            if (nums[row + 1][col] == -1 && nums[row + 1][col + 1] == -1)
            {
                nums[row][col] = -1;
            }
            else
            {
                nums[row][col] += max(nums[row + 1][col], nums[row + 1][col + 1]);
            }
        }
    }
    cout << nums[0][0] << endl;
    return 0;
}