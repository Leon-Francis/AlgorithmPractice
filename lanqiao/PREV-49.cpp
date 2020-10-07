/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-10-07 21:14:16
 * @LastEditTime: 2020-10-07 21:14:19
 * @LastEditors: Leon-Francis
 * @Description: 发现环
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-49.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;

void dfs(int way, int preway, int n, vector<int> &road, vector<int> &ans, vector<pair<int, int>> &edge)
{
    if(ans.size() != 0)
    {
        return;
    }
    for (int i = 0; i < road.size(); i++)
    {
        if (way == road[i])
        {
            for (int j = i; j < road.size(); j++)
            {
                ans.push_back(road[j]);
            }
            return;
        }
    }
    road.push_back(way);
    for (int i = 0; i < n; i++)
    {
        if (edge[i].first == way && edge[i].second != preway)
        {
            dfs(edge[i].second, way, n, road, ans, edge);
        }
        else if (edge[i].second == way && edge[i].first != preway)
        {
            dfs(edge[i].first, way, n, road, ans, edge);
        }
    }
    road.pop_back();
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    vector<int> road;
    vector<int> ans;
    vector<pair<int, int>> edge(n);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> edge[i].first >> edge[i].second;
    }
    int preway = 0;
    int way = 1;
    dfs(way, preway, n, road, ans, edge);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
