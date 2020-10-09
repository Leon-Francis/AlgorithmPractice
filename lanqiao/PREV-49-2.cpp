/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-10-09 20:13:22
 * @LastEditTime: 2020-10-09 20:13:24
 * @LastEditors: Leon-Francis
 * @Description: PREV-49:发现环
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-49-2.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;

int fa[100000];
int beginnode = 0;
int endnode = 0;

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
        return find(fa[x]);
    }
}

void merge(int i, int j)
{
    if ((i = find(i)) == (j = find(j)))
    {
        beginnode = i;
        endnode = j;
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
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    init(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    vector<int> cir;
    while (1)
    {
        int rawbegin = beginnode;
        cir.push_back(beginnode);
        while (fa[beginnode] != -1 || beginnode != endnode)
        {
            beginnode = fa[beginnode];
            cir.push_back(beginnode);
        }
        if (beginnode == endnode)
        {
            break;
        }
        else
        {
            endnode = fa[endnode];
            beginnode = rawbegin;
            cir.clear();
        }
    }
    sort(cir.begin(), cir.end());

    for (int i = 0; i < cir.size(); i++)
    {
        cout << cir[i] << " ";
    }
    cout << endl;
    return 0;
}
//不知道为什么实在解不出这题，放弃
