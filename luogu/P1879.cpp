/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-15 22:30:44
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-15 22:57:05
 * @LastEditors: Leon-Francis
 * @Description: 状压dp: Corn Fields G
 * @FilePath: /AlgorithmPractice/luogu/P1879.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;

int M, N;
int field[13][13];
int f[13][4097] = {0};

int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> field[i][j];
        }
    }
    int max_statue = 1 << N;
    max_statue--;
    for (int index = 0; index < M; index++)
    {
        int temp = 0;
        for (int i = 0; i < N; i++)
        {
            if (field[index][i] == 1)
            {
                temp += (1 << i);
            }
        }
        for (int num = 0; num <= max_statue; num++)
        {
            if (((num << 1) & num) == 0 && ((num >> 1) & num) == 0 && ((num | temp) == temp))
            {
                for (int t = 0; t <= max_statue; t++)
                {
                    if ((num & t) == 0)
                    {
                        if (index == 0)
                        {
                            f[index][num] = 1;
                        }
                        else
                        {
                            f[index][num] = (f[index][num] + f[index - 1][t]) % 100000000;
                        }
                    }
                }
            }
            else
            {
                f[index][num] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= max_statue; i++)
    {
        ans = (ans + f[M - 1][i]) % 100000000;
    }
    cout << ans << endl;
    return 0;
}
//AC