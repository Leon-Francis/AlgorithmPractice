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
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string basic_str;

int value(string str)
{
    int result = 0;
    for (int i = 0; i < basic_str.size(); i++)
    {
        if (str[i] == basic_str[i])
        {
            result++;
        }
    }
    return result;
}

bool cmp(pair<string, int> str_1, pair<string, int> str_2)
{
    return value(str_1.first) + str_1.second > value(str_2.first) + str_2.second;
}

bool is_in(string str, vector<pair<string, int>> already, vector<pair<string, int>> choice)
{
    for (int i = 0; i < already.size(); i++)
    {
        if (already[i].first == str)
        {
            return true;
        }
    }
    for (int i = 0; i < choice.size(); i++)
    {
        if (choice[i].first == str)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    pair<string, int> str;
    cin >> str.first;
    cin >> basic_str;
    str.second = 0;
    vector<pair<string, int>> choice;
    vector<pair<string, int>> already;
    choice.push_back(str);
    while (choice[choice.size() - 1].first != basic_str && choice.size() > 0)
    {
        pair<string, int> ex_str = choice[choice.size() - 1];
        already.push_back(ex_str);
        choice.pop_back();
        int index = ex_str.first.find('*');
        for (int j = -3; j < 0; j++)
        {
            if (index + j >= 0)
            {
                string rep_str = ex_str.first;
                rep_str[index] = rep_str[index + j];
                rep_str[index + j] = '*';
                if (!is_in(rep_str, already, choice))
                {
                    pair<string, int> new_node(rep_str, ex_str.second + 1);
                    choice.push_back(new_node);
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
                if (!is_in(rep_str, already, choice))
                {
                    pair<string, int> new_node(rep_str, ex_str.second + 1);
                    choice.push_back(new_node);
                }
            }
        }
        sort(choice.begin(), choice.end(), cmp);
    }
    if (choice[choice.size() - 1].first == basic_str)
    {
        cout << choice[choice.size() - 1].second << endl;
    }
    else
    {
        cout << "no result" << endl;
    }
    return 0;
}