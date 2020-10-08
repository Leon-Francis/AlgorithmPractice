/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-10-08 20:37:47
 * @LastEditTime: 2020-10-08 20:37:53
 * @LastEditors: Leon-Francis
 * @Description: 并查集
 * @FilePath: /AlgorithmPractice/lanqiao/bingchaji.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5000

int fa[MAXN];

// 按秩合并
void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        fa[i] = -1;
    }
}

int find(int x) //寻找x的父节点+路径压缩
{
    if (fa[x] < 0)
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
    i = find(i);
    j = find(j);
    if (i == j)
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
/*
亲戚问题
题目背景
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。
题目描述
规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果x,y是亲戚，那么x的亲戚都是y的亲戚，y的亲戚也都是x的亲戚。
输入格式
第一行：三个整数n,m,p，（n<=5000,m<=5000,p<=5000），分别表示有n个人，m个亲戚关系，询问p对亲戚关系。
以下m行：每行两个数Mi，Mj，1<=Mi，Mj<=N，表示Mi和Mj具有亲戚关系。
接下来p行：每行两个数Pi，Pj，询问Pi和Pj是否具有亲戚关系。
输出格式
P行，每行一个’Yes’或’No’。表示第i个询问的答案为“具有”或“不具有”亲戚关系。
*/
int main(int argc, char const *argv[])
{
    int n, m, p;
    cin >> n >> m >> p;
    init(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    for (int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
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
