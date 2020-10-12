#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 41;
int F[MAXN][MAXN][MAXN][MAXN], num[351], g[5], n, m, x;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    F[0][0][0][0] = num[1];
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        g[x]++;
    }
    for (int a = 0; a <= g[1]; a++)
        for (int b = 0; b <= g[2]; b++)
            for (int c = 0; c <= g[3]; c++)
                for (int d = 0; d <= g[4]; d++)
                {
                    int r = 1 + a + b * 2 + c * 3 + d * 4;
                    if (a != 0)
                        F[a][b][c][d] = max(F[a][b][c][d], F[a - 1][b][c][d] + num[r]);
                    if (b != 0)
                        F[a][b][c][d] = max(F[a][b][c][d], F[a][b - 1][c][d] + num[r]);
                    if (c != 0)
                        F[a][b][c][d] = max(F[a][b][c][d], F[a][b][c - 1][d] + num[r]);
                    if (d != 0)
                        F[a][b][c][d] = max(F[a][b][c][d], F[a][b][c][d - 1] + num[r]);
                }
    cout << F[g[1]][g[2]][g[3]][g[4]];
    return 0;
}