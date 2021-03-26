/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2021-03-26 21:30:48
 * @LastEditTime: 2021-03-26 21:30:48
 * @LastEditors: Leon-Francis
 * @Description: 填字母游戏
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-46.cpp
 * (C)Copyright 2019-2020, Leon-Francis
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;
char choose[2] = {'L', 'O'};
map<string, int> record;
int dfs(string str)
{
    if (record.find(str) != record.end())
    {
        return record[str];
    }
    if (str.find("LO*") != -1 || str.find("*OL") != -1 || str.find("L*L") != -1)
    {
        record[str] = 1;
        return 1;
    }
    if (str.find("*") == -1 && str.find("LOL") == -1)
    {
        record[str] = 0;
        return 0;
    }
    bool draw = false;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '*')
        {
            for (int j = 0; j < 2; j++)
            {
                str[i] = choose[j];
                int flag = dfs(str);
                str[i] = '*';
                if (flag == 1)
                {
                    continue;
                }
                else if (flag == -1)
                {
                    return 1;
                }
                else if (flag == 0)
                {
                    draw = true;
                }
            }
        }
    }
    if (draw)
    {
        record[str] = 0;
        return 0;
    }
    record[str] = -1;
    return -1;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        cout << dfs(str) << endl;
    }
    return 0;
}
//正确！
//博弈论+深度优先
// 带平局的博弈类解法模版大概如下：

// 给定一个局面x，f(x) 是计算我方通过最优步骤走是输还是赢还是平局。

//     胜负平   f(局面x)
// {
//          边界值处理

//      for (所有可走的局面) ｛

//             试着走一步，得到一个新局面y

//             交给对手走，即判断f(y) 的返回值

//             恢复局面

//             如果返回值为负，则我必赢，即这步是我的最优走法

//             如果返回值为赢，则我必输，不可取

//             如果返回值为平，则我至少可以逼平对手，先存着这个结果

//      ｝

//      如果算的可以逼平，则返回平

//      否则返回负