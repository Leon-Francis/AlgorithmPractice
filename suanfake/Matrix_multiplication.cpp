#include <iostream>
using namespace std;

void PrintMatrixMul(int keys[6][6], int i, int j)
{
    if (keys[i][j] == i) //左半部分只有一个元素
    {
        cout << "A" << i + 1;
    }
    else
    {
        cout << "(";
        PrintMatrixMul(keys, i, keys[i][j]); //递归查询以keys[i][j]为分割的左半部分
        cout << ")";
    }
    if (keys[i][j] + 1 == j) //右半部分只有一个元素
    {
        cout << "A" << j + 1;
    }
    else
    {
        cout << "(";
        PrintMatrixMul(keys, keys[i][j] + 1, j); //递归查询以keys[i][j]为分割的右半部分
        cout << ")";
    }
    return;
}

int main(int argc, char const *argv[])
{
    int P[7] = {1, 5, 10, 100, 1, 2, 100};
    int results[6][6] = {};
    int keys[6][6] = {};
    for (int i = 1; i < 6; i++) //这里i指的是填第i个斜列
    {
        for (int j = 0; j < 6 - i; j++) //这里j指的是填第i斜列的第j个
        {                               //由上述i，j可得此时在填的位置为results[j][j+i]
            results[j][j + i] = results[j][j] + results[j + 1][j + i] + P[j] * P[j + 1] * P[j + i + 1];
            keys[j][j + i] = j;
            for (int t = 0; t < i; t++) //这里j+t即为k
            {
                int result = results[j][j + t] + results[j + t + 1][j + i] + P[j] * P[j + t + 1] * P[j + i + 1];
                if (result < results[j][j + i])
                {
                    results[j][j + i] = result;
                    keys[j][j + i] = j + t;
                }
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << keys[i][j] << " ";
        }
        cout << endl;
    }
    PrintMatrixMul(keys, 0, 5);
    cout << endl;
    return 0;
}
