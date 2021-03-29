/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2021-03-29 21:23:48
 * @LastEditTime: 2021-03-29 21:23:48
 * @LastEditors: Leon-Francis
 * @Description: 图形排版
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-45.cpp
 * (C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<pair<int, int>> picts(N);
    int min_height = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        cin >> picts[i].first >> picts[i].second;
    }
    for (int skip_i = 0; skip_i < N; skip_i++)
    {
        int height = 0;
        int height_now = 0;
        int lenth = M;
        for (int index = 0; index < N; index++)
        {
            if (index == skip_i)
            {
                continue;
            }
            if (lenth < picts[index].first)
            {
                int h = ceil((double)(picts[index].second) / (double)(picts[index].first) * (double)(lenth));
                if (height_now < h)
                {
                    height_now = h;
                }
                height += height_now;
                height_now = 0;
                lenth = M;
            }
            else
            {
                if (height_now < picts[index].second)
                {
                    height_now = picts[index].second;
                }
                lenth -= picts[index].first;
                if (lenth == 0)
                {
                    height += height_now;
                    height_now = 0;
                    lenth = M;
                }
            }
        }
        if (height_now != 0)
        {
            height += height_now;
            height_now = 0;
            lenth = M;
        }
        if (min_height > height)
        {
            min_height = height;
        }
        height = 0;
    }
    cout << min_height << endl;
    return 0;
}
//暴力题解 超时 只拿到50分