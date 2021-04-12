/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-11 19:53:37
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-12 17:12:01
 * @LastEditors: Leon-Francis
 * @Description: 圆形石子堆合并
 * @FilePath: /AlgorithmPractice/luogu/P1880.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;

int N;
int weight[101];
int nums[101][101] = {0};
int nums_min[101][101] = {0};

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // left j, right j + i mod N
            int max_w = 0;
            int min_w = nums_min[j][j] + nums_min[(j + 1) % N][(j + i) % N];
            for (int k = 0; k < i; k++)
            {
                // (j, j+k mod N) (j+k+1 mod N, j+i mod N)
                max_w = max(nums[j][(j + k) % N] + nums[(j + k + 1) % N][(j + i) % N], max_w);
                min_w = min(nums_min[j][(j + k) % N] + nums_min[(j + k + 1) % N][(j + i) % N], min_w);
                nums[j][(j + i) % N] += weight[(j + k) % N];
                nums_min[j][(j + i) % N] += weight[(j + k) % N];
            }
            nums[j][(j + i) % N] += weight[(j + i) % N] + max_w;
            nums_min[j][(j + i) % N] += weight[(j + i) % N] + min_w;
        }
    }
    int result = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        if (nums_min[i][(i + N - 1) % N] < result)
        {
            result = nums_min[i][(i + N - 1) % N];
        }
    }
    cout << result << endl;
    int result_m = 0;
    for (int i = 0; i < N; i++)
    {
        if (nums[i][(i + N - 1) % N] > result_m)
        {
            result_m = nums[i][(i + N - 1) % N];
        }
    }
    cout << result_m << endl;
    return 0;
}
// AC