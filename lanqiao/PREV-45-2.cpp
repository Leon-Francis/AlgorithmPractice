/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2021-03-30 16:58:48
 * @LastEditTime: 2021-03-30 16:58:48
 * @LastEditors: Leon-Francis
 * @Description: 图形排版 方法2
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-45.cpp
 * (C)Copyright 2019-2020, Leon-Francis
 */
//采用预处理的方法 以空间换时间
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<pair<int, int>> picts(N);
    for (int i = 0; i < N; i++)
    {
        cin >> picts[i].first >> picts[i].second;
    }
    vector<vector<int>> pre_ord(N, vector<int>(3));
    vector<int> last_ord(N);
    int height = 0;
    int height_now = 0;
    int lenth = M;
    for (int index = 0; index < N; index++)
    {
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
            pre_ord[index][0] = height;
            pre_ord[index][1] = height_now;
            pre_ord[index][2] = lenth;
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
            pre_ord[index][0] = height;
            pre_ord[index][1] = height_now;
            pre_ord[index][2] = lenth;
        }
    }
    for (int index = N - 1; index >= 0; index--)
    {
        int height_now = 0;
        int lenth = M;
        for (int i = index; i < N; i++)
        {
            if (lenth < picts[index].first)
            {
                int h = ceil((double)(picts[index].second) / (double)(picts[index].first) * (double)(lenth));
                if (height_now < h)
                {
                    height_now = h;
                }
                if (i + 1 < N)
                {
                    last_ord[index] = last_ord[i + 1] + height_now;
                }
                else
                {
                    last_ord[index] = height_now;
                }
                lenth = 0;
                break;
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
                    if (i + 1 < N)
                    {
                        last_ord[index] = last_ord[i + 1] + height_now;
                    }
                    else
                    {
                        last_ord[index] = height_now;
                    }
                    break;
                }
            }
        }
        if (lenth > 0)
        {
            last_ord[index] = height_now;
        }
    }
    int min_height = INT_MAX;
    for (int skip = 0; skip < N; skip++)
    {
        height = 0;
        height_now = 0;
        lenth = M;
        if (skip == 0)
        {
            height = last_ord[1];
            if (min_height > height)
            {
                min_height = height;
            }
        }
        else if (skip == N - 1)
        {
            height = pre_ord[N - 2][0] + pre_ord[N - 2][1];
            if (min_height > height)
            {
                min_height = height;
            }
        }
        else
        {
            height = pre_ord[skip - 1][0];
            height_now = pre_ord[skip - 1][1];
            lenth = pre_ord[skip - 1][2];
            if (lenth == 0)
            {
                height += last_ord[skip + 1];
                if (min_height > height)
                {
                    min_height = height;
                }
            }
            else
            {
                int index;
                for (index = skip + 1; index < N; index++)
                {
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
                        break;
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
                            break;
                        }
                    }
                }
                if (index >= N - 1)
                {
                    height += height_now;
                }
                else
                {
                    height += last_ord[index + 1];
                }
                if (min_height > height)
                {
                    min_height = height;
                }
            }
        }
    }
    cout << min_height << endl;
    return 0;
}
//只对了第一个测试点，思路没错，可能是代码某个地方出了问题，但是写的太复杂了，我不想找了…………