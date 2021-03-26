/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2021-03-26 10:28:15
 * @LastEditTime: 2021-03-26 10:28:15
 * @LastEditors: Leon-Francis
 * @Description: 区间移位
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-47.cpp
 * (C)Copyright 2019-2020, Leon-Francis
 */
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> edge_1, pair<int, int> edge_2)
{
    if (edge_1.second == edge_2.second)
    {
        return edge_1.first < edge_2.first;
    }
    else
    {
        return edge_1.second < edge_2.second;
    }
}

bool if_array(int dis, vector<pair<int, int>> edges, int l_bound, int r_bound)
{
    while (!edges.empty() && r_bound > l_bound)
    {
        for (int index = 0; index < edges.size(); index++)
        {
            int l = edges[index].first - dis;
            int r = edges[index].first + dis;
            if (l <= l_bound && l_bound <= r)
            {
                l_bound = l_bound + edges[index].second - edges[index].first;
                edges.erase(edges.begin() + index);
                break;
            }
            else
            {
                if (r < l_bound)
                {
                    if (edges[index].second + dis >= l_bound)
                    {
                        l_bound = edges[index].second + dis;
                        edges.erase(edges.begin() + index);
                        break;
                    }
                }
            }
            if(index == edges.size() - 1)
            {
                return false;
            }
        }
    }
    if (l_bound >= r_bound)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n);
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first *= 2;
        edges[i].second *= 2;
    }
    sort(edges.begin(), edges.end(), cmp);
    int dis_l = 0;
    int dis_r = 20000;
    int dis_mid;
    while (dis_r - dis_l > 1)
    {
        dis_mid = (dis_l + dis_r) / 2;
        if (if_array(dis_mid, edges, 0, 20000))
        {
            dis_r = dis_mid;
        }
        else
        {
            dis_l = dis_mid;
        }
    }
    double ans = dis_r;
    cout << ans / 2 << endl;
    return 0;
}
//正确！