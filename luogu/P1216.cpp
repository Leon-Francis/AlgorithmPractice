/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-16 20:22:57
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-16 20:30:38
 * @LastEditors: Leon-Francis
 * @Description: [USACO1.5][IOI1994]数字三角形 Number Triangles
 * @FilePath: /AlgorithmPractice/luogu/P1216.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;

int N;
int nums[1001][1001];

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