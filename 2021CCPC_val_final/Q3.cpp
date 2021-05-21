/*** 
 * @Author: Leon-Francis
 * @Date: 2021-05-21 20:14:45
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-05-21 21:21:21
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /AlgorithmPractice/2021CCPC_val_final/Q3.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;

int nums[1000001];
int revers_nums[1000001] = {0};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }
    for (int i = 0; i < m; i++)
    {
        int swi_num;
        cin >> swi_num;
        int temp = nums[swi_num - 1];
        nums[swi_num - 1] = nums[swi_num];
        nums[swi_num] = temp;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << nums[i] << " ";
    }
    cout << nums[n - 1] << endl;
    revers_nums[n - 1] = 0;
    long long ans = 0;
    for (int right_num = n - 2; right_num >= 0; right_num--)
    {
        revers_nums[right_num] = 0;
        for (int i = right_num + 1; i < n; i++)
        {
            if (nums[i] == nums[right_num] + 1)
            {
                revers_nums[right_num] += revers_nums[i];
                break;
            }
            else if (nums[i] < nums[right_num])
            {
                revers_nums[right_num] += 1;
            }
        }
        ans += revers_nums[right_num];
    }
    cout << ans << endl;
    return 0;
}