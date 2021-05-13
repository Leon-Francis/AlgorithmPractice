/*** 
 * @Author: Leon-Francis
 * @Date: 2021-05-13 20:08:13
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-05-13 20:51:49
 * @LastEditors: Leon-Francis
 * @Description: 排列
 * @FilePath: /AlgorithmPractice/2021CCPC_val/Q3.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int out_num = 0;

void output(vector<int> cards, int num)
{
    if (cards.size() == 1)
    {
        out_num++;
        if (out_num % 6 == 0)
        {
            cout << num * 10 + cards[0];
        }
        else
        {
            cout << num * 10 + cards[0] << " ";
        }
        return;
    }
    if (cards.size() == 4)
    {
        for (int i = 0; i < cards.size(); i++)
        {
            int temp_num = num * 10 + cards[i];
            vector<int> temp_cards = cards;
            temp_cards.erase(temp_cards.begin() + i);
            output(temp_cards, temp_num);
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < cards.size(); i++)
    {
        int temp_num = num * 10 + cards[i];
        vector<int> temp_cards = cards;
        temp_cards.erase(temp_cards.begin() + i);
        output(temp_cards, temp_num);
    }
    return;
}

int main()
{
    vector<int> cards(4);
    int N;
    cin >> N;
    for (int n = 0; n < N; n++)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> cards[i];
        }
        sort(cards.begin(), cards.end(), less<int>());
        int out_num = 0;
        output(cards, 0);
        if (n != N - 1)
        {
            cout << endl;
        }
    }
    return 0;
}