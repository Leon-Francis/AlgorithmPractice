/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-22 19:26:01
 * @LastEditTime: 2020-09-22 20:40:23
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/lanqiao/PREV-54.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
#include <vector>
using namespace std;

int find_fa(vector<int> &nums, int x)
{
    if (nums[x] < 0)
    {
        return x;
    }
    nums[x] = find_fa(nums, nums[x]);
    return nums[x];
}

void merge_tr(vector<int> &nums, int a, int b)
{
    if ((a = find_fa(nums, a)) == (b = find_fa(nums, b)))
    {
        return;
    }
    if (nums[a] < nums[b])
    {
        nums[a] += nums[b];
        nums[b] = a;
    }
    else
    {
        nums[b] += nums[a];
        nums[a] = b;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<int> nums(m * n);
    for (int i = 0; i < m * n; i++)
    {
        nums[i] = -1;
    }
    int k;
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        merge_tr(nums, a - 1, b - 1);
    }
    int sum = 0;
    for (int i = 0; i < m * n; i++)
    {
        if (nums[i] < 0)
        {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
