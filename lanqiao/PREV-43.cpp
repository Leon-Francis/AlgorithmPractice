/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-07 21:22:17
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-07 22:23:53
 * @LastEditors: Leon-Francis
 * @Description: 拉马车
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-43.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main()
{
    queue<char> a_hold;
    queue<char> b_hold;
    vector<char> pool;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
    {
        a_hold.push(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        b_hold.push(b[i]);
    }
    bool a_win = true;
    bool b_win = true;
    while (1)
    {
        while (1)
        {
            a_win = false;
            char temp = a_hold.front();
            a_hold.pop();
            int index;
            for (index = pool.size() - 1; index >= 0; index--)
            {
                if (pool[index] == temp)
                {
                    break;
                }
            }
            if (index == -1)
            {
                pool.push_back(temp);
            }
            else
            {
                a_hold.push(temp);
                int nums = pool.size() - index;
                for (int i = 0; i < nums; i++)
                {
                    temp = pool.back();
                    pool.pop_back();
                    a_hold.push(temp);
                }
                a_win = true;
            }
            if (a_hold.size() == 0)
            {
                int nums = b_hold.size();
                for (int i = 0; i < nums; i++)
                {
                    char temp = b_hold.front();
                    b_hold.pop();
                    cout << temp;
                }
                cout << endl;
                return 0;
            }
            if(!a_win)
            {
                break;
            }
        }

        while (1)
        {
            b_win = false;
            char temp = b_hold.front();
            b_hold.pop();
            int index;
            for (index = pool.size() - 1; index >= 0; index--)
            {
                if (pool[index] == temp)
                {
                    break;
                }
            }
            if (index == -1)
            {
                pool.push_back(temp);
            }
            else
            {
                b_hold.push(temp);
                int nums = pool.size() - index;
                for (int i = 0; i < nums; i++)
                {
                    temp = pool.back();
                    pool.pop_back();
                    b_hold.push(temp);
                }
                b_win = true;
            }
            if (b_hold.size() == 0)
            {
                int nums = a_hold.size();
                for (int i = 0; i < nums; i++)
                {
                    char temp = a_hold.front();
                    a_hold.pop();
                    cout << temp;
                }
                cout << endl;
                return 0;
            }
            if(!b_win)
            {
                break;
            }
        }
    }
}
// 正确
// 然而并不知道-1的情况怎么判断，在网上查了才知道这道题并没有-1的检测点