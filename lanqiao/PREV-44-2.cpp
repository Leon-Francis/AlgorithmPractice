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
//bfs
#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

int dir[] = {-3, -2, -1, 1, 2, 3}; //可移动的 6种方案
struct situation
{                              //定义结构体：形势
    string str;                //当前形势下的字符串
    int step;                  //得到当前形势所需的步数
    situation(string s, int n) //构造函数
    {
        str = s, step = n;
    }
};
queue<situation> q;
set<string> s;

void bfs(string start, string target)
{
    if (start == target)
    {
        cout << 0 << endl;
        return;
    }
    q.push(situation(start, 0));
    s.insert(start);
    while (!q.empty())
    {
        situation now = q.front();
        q.pop();
        string str = now.str;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != '*')
                continue; //仅仅对空杯子的位置进行换位
            for (int j = 0; j < 6; j++)
            { //尝试所有可以交换的方案
                int n = i + dir[j];
                if (n >= 0 && n < str.length()) //如果当前换位合法
                {
                    swap(str[i], str[n]); //交换青蛙和空杯的位置
                    if (str == target)
                    { //如果已经等于目标字符则输出
                        cout << now.step + 1 << endl;
                        return;
                    }
                    if (!s.count(str))
                    {                  //如果当前字符串还未出现过
                        s.insert(str); //那就标记该字符串为已走
                        q.push(situation(str, now.step + 1));
                    }
                    swap(str[i], str[n]); //恢复现场
                }
            }
        }
    }
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    bfs(str1, str2);
    return 0;
}