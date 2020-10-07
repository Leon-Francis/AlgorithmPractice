#include <iostream>
using namespace std;

int Mod6(int num)
{
    if (num > 6)
    {
        return num - 6;
    }
}

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
    if (Mod6(keys[i][j] + 1) == j)
    {
        cout << "W" << j;
    }
    else
    {
        cout << "(";
        PrintMatrixMul(keys, Mod6(keys[i][j] + 1), j);
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
        for (int j = 0; j < 6; j++)
        {
            results[j + 1][Mod6(j + i + 2)] = results[j + 1][j + 1] + results[Mod6(j + 2)][Mod6(j + i + 2)];
            keys[j + 1][Mod6(j + i + 2)] = j + 1;
            for (int k = j + 1;;)
            {
                int result = results[j + 1][k] + results[Mod6(k + 1)][Mod6(j + i + 2)];
                if (results[j + 1][Mod6(j + i + 2)] > result)
                {
                    results[j + 1][Mod6(j + i + 2)] = result;
                    keys[j + 1][Mod6(j + i + 2)] = k;
                }
                k++;
                k = Mod6(k);
                if (k == Mod6(j + i + 2))
                {
                    break;
                }
            }
            for (int t = j + 1;;)
            {
                results[j + 1][Mod6(j + i + 2)] += W[t];
                t++;
                t = Mod6(t);
                if (t == Mod6(j + i + 3))
                {
                    break;
                }
            }
        }
    }
    int min = results[1][6];
    int minnum = 1;
    for (int i = 2; i <= 6; i++)
    {
        if (min > results[i][i - 1])
        {
            min = results[i][i - 1];
            minnum = i;
        }
    }
    cout << "最优值为" << min << endl;
    PrintMatrixMul(keys, minnum, Mod6(minnum + 5));
    return 0;
}
