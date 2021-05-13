/*** 
 * @Author: Leon-Francis
 * @Date: 2021-05-13 20:53:00
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-05-13 20:59:56
 * @LastEditors: Leon-Francis
 * @Description: 倒三角形
 * @FilePath: /AlgorithmPractice/2021CCPC_val/Q4.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int left = 0; left < i; left++)
        {
            cout << " ";
        }
        for (int left = i; left < N; left++)
        {
            cout << "#";
        }
        for (int num = 0; num < N - i - 1; num++)
        {
            cout << "#";
        }
        cout << endl;
    }
    return 0;
}