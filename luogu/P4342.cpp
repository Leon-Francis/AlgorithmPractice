/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-13 21:20:01
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-13 22:50:56
 * @LastEditors: Leon-Francis
 * @Description: 动态规划：Polygon
 * @FilePath: /AlgorithmPractice/luogu/P4342.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
#include <vector>
using namespace std;

int N;
int vertexs[51];
char edges[51];

int dp(int v[51], char e[51])
{
    int nums_max[51][51];
    int nums_min[51][51];
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            nums_max[i][j] = -INT32_MAX;
            nums_min[i][j] = INT32_MAX;
        }
    }
    for (int i = 0; i < N; i++)
    {
        nums_max[i][i] = v[i];
        nums_min[i][i] = v[i];
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j + i < N; j++) //nums_max[j][j+i]
        {
            for (int k = 0; k < i; k++) //nums_max[j][j+k] nums_max[j+k+1][j+i]
            {
                if (e[j + k] == 't')
                {
                    nums_max[j][j + i] = max(nums_max[j][j + i], (nums_max[j][j + k] + nums_max[j + k + 1][j + i]));
                    nums_min[j][j + i] = min(nums_min[j][j + i], (nums_min[j][j + k] + nums_min[j + k + 1][j + i]));
                }
                else
                {
                    nums_max[j][j + i] = max(nums_max[j][j + i], max(nums_max[j][j + k] * nums_max[j + k + 1][j + i], max(nums_min[j][j + k] * nums_min[j + k + 1][j + i], max(nums_max[j][j + k] * nums_min[j + k + 1][j + i], nums_min[j][j + k] * nums_max[j + k + 1][j + i]))));
                    nums_min[j][j + i] = min(nums_min[j][j + i], min(nums_max[j][j + k] * nums_max[j + k + 1][j + i], min(nums_min[j][j + k] * nums_min[j + k + 1][j + i], min(nums_max[j][j + k] * nums_min[j + k + 1][j + i], nums_min[j][j + k] * nums_max[j + k + 1][j + i]))));
                }
            }
        }
    }
    return nums_max[0][N - 1];
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> edges[i];
        cin >> vertexs[i];
    }
    int v[51];
    char e[51];
    vector<int> result;
    int max_res = -INT32_MAX;
    for (int i = 0; i < N; i++)
    {
        v[0] = vertexs[i];
        for (int j = 1; j < N; j++)
        {
            e[j - 1] = edges[(i + j) % N];
            v[j] = vertexs[(i + j) % N];
        }
        int temp_ans = dp(v, e);
        if (temp_ans > max_res)
        {
            max_res = temp_ans;
            result.clear();
            result.push_back(i + 1);
        }
        else if (temp_ans == max_res)
        {
            result.push_back(i + 1);
        }
    }
    cout << max_res << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
// AC