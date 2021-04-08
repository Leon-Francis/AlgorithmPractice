/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-08 20:18:39
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-08 20:32:05
 * @LastEditors: Leon-Francis
 * @Description: Excel地址
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-41.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<char> out_str;
    int num;
    cin >> num;
    while(num != 0)
    {
        out_str.push_back('A' + ((num - 1) % 26));
        num = (num - 1) / 26;
    }
    while(!out_str.empty())
    {
        cout << out_str.back();
        out_str.pop_back();
    }
    cout << endl;
    return 0;
}
//正确