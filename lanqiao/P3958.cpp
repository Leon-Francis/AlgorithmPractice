/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-10-08 21:12:01
 * @LastEditTime: 2020-10-08 21:12:23
 * @LastEditors: Leon-Francis
 * @Description: 洛谷P3958: 奶酪
 * @FilePath: /AlgorithmPractice/lanqiao/P3958.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int fa[1000];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        fa[i] = -1;
    }
}

int find(int x)
{
    if (fa[x] == -1)
    {
        return x;
    }
    else
    {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merge(int i, int j)
{
    if ((i = find(i)) == (j = find(j)))
    {
        return;
    }
    if (fa[i] < fa[j])
    {
        fa[j] = i;
    }
    else
    {
        fa[i] = j;
    }
    if (fa[i] == fa[j])
    {
        fa[j]--;
    }
}

bool next_to(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2, ll r)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) <= 4 * r * r;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        ll h, r;
        cin >> n >> h >> r;
        init(n);
        fa[n] = -1;     //顶部
        fa[n + 1] = -1; //底部
        vector<vector<int>> pos(n);
        for (int j = 0; j < n; j++)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            pos[j].push_back(x);
            pos[j].push_back(y);
            pos[j].push_back(z);
            if (z <= r)
            {
                merge(j, n);
            }
            if (z + r >= h)
            {
                merge(j, n + 1);
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (next_to(pos[j][0], pos[j][1], pos[j][2], pos[k][0], pos[k][1], pos[k][2], r))
                {
                    merge(j, k);
                }
            }
        }
        if(find(n) == find(n+1))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}

//bingo