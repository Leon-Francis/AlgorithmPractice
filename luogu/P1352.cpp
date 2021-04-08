/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-24 09:33:48
 * @LastEditTime: 2020-09-24 10:02:33
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/lanqiao/P1352.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;


void dp(int x, vector<vector<int>> &son, vector<vector<int>> &f)
{
    for (int i = 0; i < son[x].size(); i++)
    {
        int y = son[x][i];
        dp(y, son, f);
        f[x][0] += max(f[y][0], f[y][1]);
        f[x][1] += f[y][0];
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> R(n);
    vector<int> V(n);
    for (int i = 0; i < n; i++)
    {
        cin >> R[i];
    }
    vector<vector<int>> son(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        son[y-1].push_back(x-1);
        V[x-1] = 1;
    }
    int root;
    for (int i = 0; i < n; i++)
    {
        if (!V[i])
        {
            root = i;
            break;
        }
    }
    vector<vector<int>> f(n);
    for (int i = 0; i < n; i++)
    {
        f[i].push_back(0);
        f[i].push_back(R[i]);
    }
    dp(root, son, f);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}
