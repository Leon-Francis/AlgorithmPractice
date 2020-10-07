#include <iostream>
using namespace std;

void PrintMatrixMul(int keys[7][7], int i, int j)
{
    if (keys[i][j] == i)
    {
        cout << "W" << i;
    }
    else
    {
        cout << "(";
        PrintMatrixMul(keys, i, keys[i][j]);
        cout << ")";
    }
    if (keys[i][j] + 1 == j)
    {
        cout << "W" << j ;
    }
    else
    {
        cout << "(";
        PrintMatrixMul(keys, keys[i][j] + 1, j);
        cout << ")";
    }
    return;
}

int main(int argc, char const *argv[])
{
    int W[7] = {0, 4, 3, 5, 2, 1, 6};
    int results[7][7] = {};
    int keys[7][7] = {};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            results[j + 1][j + i + 2] = results[j + 1][j + 1] + results[j + 2][j + i + 2];
            keys[j + 1][j + i + 2] = j + 1;
            for (int k = j + 1; k <= j + i + 1; k++)
            {
                int result = results[j + 1][k] + results[k + 1][j + i + 2];
                if (results[j + 1][j + i + 2] > result)
                {
                    results[j + 1][j + i + 2] = result;
                    keys[j + 1][j + i + 2] = k;
                }
            }
            for (int t = j + 1; t <= j + i + 2; t++)
            {
                results[j + 1][j + i + 2] += W[t];
            }
        }
    }
    cout << "最优值为" << results[1][6] << endl;
    PrintMatrixMul(keys, 1, 6);
    return 0;
}
