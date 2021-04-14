/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-14 21:46:51
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-14 22:58:22
 * @LastEditors: Leon-Francis
 * @Description: 状压dp：关灯问题Ⅱ
 * @FilePath: /AlgorithmPractice/luogu/P2622.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int swi[101][11];
queue<pair<int, int>> wait;
vector<int> already;

int change(int ori, int num)
{
    int and_op = 0;
    int or_op = 0;
    for (int i = 0; i < N; i++)
    {
        if (swi[num][i] == 0)
        {
            and_op += (1 << i);
        }
        if (swi[num][i] == -1)
        {
            or_op += (1 << i);
            and_op += (1 << i);
        }
    }
    return (ori & and_op) | or_op;
}

bool is_in(int x)
{
    for (int i = 0; i < already.size(); i++)
    {
        if (already[i] == x)
        {
            return true;
        }
    }
    return false;
}

int bfs()
{
    if (wait.empty())
    {
        return -1;
    }
    int now = wait.front().first;
    int now_num = wait.front().second;
    wait.pop();
    for (int i = 0; i < M; i++)
    {
        int temp = change(now, i);
        if (temp == 0)
        {
            return now_num + 1;
        }
        else if (!is_in(temp))
        {
            wait.push(pair<int, int>(temp, now_num + 1));
            already.push_back(temp);
        }
    }
    return bfs();
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> swi[i][j];
        }
    }
    int ori_lab = 1;
    int temp = 1;
    for (int i = 0; i < N; i++)
    {
        temp *= 2;
        ori_lab = temp - 1;
    }
    wait.push(pair<int, int>(ori_lab, 0));
    already.push_back(ori_lab);
    cout << bfs() << endl;
    return 0;
}
// AC!!!!!!!!!!Yeah