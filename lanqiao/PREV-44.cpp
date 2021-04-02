/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2021-03-30 16:58:48
 * @LastEditTime: 2021-03-30 16:58:48
 * @LastEditors: Leon-Francis
 * @Description: 青蛙跳杯子
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-45.cpp
 * (C)Copyright 2019-2020, Leon-Francis
 */
//采用A*算法
#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

string basic_str;

set<string> already;

int main()
{
    pair<string, int> str;
    cin >> str.first;
    cin >> basic_str;
    str.second = 0;
    queue<pair<string, int>> choice;
    choice.push(str);
    while (!choice.empty())
    {
        pair<string, int> ex_str = choice.front();
        choice.pop();
        already.insert(ex_str.first);
        int index = ex_str.first.find('*');
        for (int j = -3; j < 0; j++)
        {
            if (index + j >= 0)
            {
                string rep_str = ex_str.first;
                rep_str[index] = rep_str[index + j];
                rep_str[index + j] = '*';
                if (rep_str == basic_str)
                {
                    cout << ex_str.second + 1 << endl;
                    return 0;
                }
                if (already.find(rep_str) == already.end())
                {
                    pair<string, int> new_node(rep_str, ex_str.second + 1);
                    choice.push(new_node);
                    already.insert(rep_str);
                }
            }
        }
        for (int j = 1; j < 4; j++)
        {
            if (index + j < ex_str.first.size())
            {
                string rep_str = ex_str.first;
                rep_str[index] = rep_str[index + j];
                rep_str[index + j] = '*';
                if (rep_str == basic_str)
                {
                    cout << ex_str.second + 1 << endl;
                    return 0;
                }
                if (already.find(rep_str) == already.end())
                {
                    pair<string, int> new_node(rep_str, ex_str.second + 1);
                    choice.push(new_node);
                    already.insert(rep_str);
                }
            }
        }
    }
    cout << "no result" << endl;
    return 0;
}
//终于不超时了！！！！！