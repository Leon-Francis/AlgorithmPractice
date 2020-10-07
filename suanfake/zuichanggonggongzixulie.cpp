#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char X[7] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char Y[7] = {'B', 'D', 'C', 'A', 'B', 'A'};
    int results[8][7] = {0};
    int keys[8][7] = {0};
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                results[i][j] = 1 + results[i - 1][j - 1];
                keys[i][j] = 1;
            }
            else
            {
                results[i][j] = results[i - 1][j] > results[i][j - 1] ? results[i - 1][j] : results[i][j - 1];
                keys[i][j] = results[i - 1][j] > results[i][j - 1] ? 3 : 2;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << keys[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
