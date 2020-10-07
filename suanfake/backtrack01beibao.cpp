#include <iostream>
using namespace std;

void backtrack(int n, int &result, int results[6], int max[6], int W[6], int P[6], int C)
{
    if (n >= 6) //递归出口
    {
        int temp = 0;
        for (int i = 0; i < 6; i++)
        {
            if (results[i] == 1)
            {
                temp += P[i];
            }
        }
        if (temp > result) //计算当前情况的价值之和是否比最大值要大
        {
            result = temp; //记录最优值
            for (int i = 0; i<6; i++) //记录最优解
            {
                max[i] = results[i];
            }
        }
        return;
    }
    int weight = 0;
    for (int i = 0; i < n; i++)
    {
        if (results[i] == 1)
        {
            weight += W[i];
        }
    }
    if (weight + W[n] > C) //当重量和大于容量时发生剪枝
    {
        results[n] = 0;
        backtrack(n + 1, result, results, max, W, P, C);
    }
    else //不发生剪枝
    {
        results[n] = 0;
        backtrack(n + 1, result, results, max, W, P, C);
        results[n] = 1;
        backtrack(n + 1, result, results, max, W, P, C);
    }
}

int main(int argc, char const *argv[])
{
    int W[6] = {3, 5, 2, 6, 4, 7};
    int P[6] = {4, 7, 5, 11, 3, 8};
    int C = 12;
    int results[6] = {};
    int max[6];
    int result = 0;
    backtrack(0, result, results, max, W, P, C);
    cout << "最优值为：" << result << endl;
    cout << "最优解为：";
    for (int i = 0; i < 6; i++)
    {
        if (max[i] == 1)
        {
            cout << i + 1 << " ";
        }
    }
    return 0;
}
