/*** 
 * @Author: Leon-Francis
 * @Date: 2021-05-13 18:47:24
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-05-13 19:12:38
 * @LastEditors: Leon-Francis
 * @Description: 回文数
 * @FilePath: /AlgorithmPractice/2021CCPC_val/Q1.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
#include <vector>
using namespace std;

bool is_begin_end(long long num)
{
    vector<int> digets;
    while (num != 0)
    {
        digets.push_back(num % 10);
        num = num / 10;
    }
    for (int idx = 0; idx <= (digets.size() - 1) / 2; idx++)
    {
        if (digets[idx] != digets[digets.size() - idx - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    for (int n = 0; n < N; n++)
    {
        long long num;
        cin >> num;
        int times = 0;
        while (!is_begin_end(num) && times <= 8)
        {
            long long begin_end_num = 0;
            long long num_copy = num;
            while (num_copy != 0)
            {
                begin_end_num = begin_end_num * 10 + num_copy % 10;
                num_copy = num_copy / 10;
            }
            num += begin_end_num;
            times++;
        }
        if (times > 8)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << times << endl;
        }
    }
    return 0;
}