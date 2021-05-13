/*** 
 * @Author: Leon-Francis
 * @Date: 2021-05-13 19:16:08
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-05-13 19:46:45
 * @LastEditors: Leon-Francis
 * @Description: 半数集问题
 * @FilePath: /AlgorithmPractice/2021CCPC_val/Q2.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <stdio.h>
using namespace std;

int nums[1001] = {0};

int dfs(int num)
{
    if (nums[num] != 0)
    {
        return nums[num];
    }
    for (int i = 0; i <= num / 2; i++)
    {
        nums[num] += dfs(i);
    }
    return nums[num];
}

int main()
{
    nums[0] = 1;
    int num;
    while (scanf("%d", &num) != EOF)
    {
        printf("%d\n", dfs(num));
    }
    return 0;
}