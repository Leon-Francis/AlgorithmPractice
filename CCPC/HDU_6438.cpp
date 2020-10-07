/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-22 09:20:01
 * @LastEditTime: 2020-09-22 19:24:45
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/CCPC/HDU_6438.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */

#include <functional>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;

#if (0)
{
    int main(int argc, char const *argv[])
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            vector<int> vec(t);
            for (int i = 0; i < t; i++)
            {
                cin >> vec[i];
            }
            int val = 0, num = 0;
            while (vec.size() > 1)
            {
                int max = vec[0];
                int max_idx = 0;
                for (int i = 1; i < vec.size(); i++)
                {
                    if (vec[i] > max)
                    {
                        max = vec[i];
                        max_idx = i;
                    }
                }
                int min = vec[max_idx];
                int min_idx = max_idx;
                for (int i = 0; i < max_idx; i++)
                {
                    if (vec[i] < min)
                    {
                        min = vec[i];
                        min_idx = i;
                    }
                }
                if (min_idx == max_idx)
                {
                    vec.erase(vec.begin() + max_idx);
                }
                else
                {
                    val += vec[max_idx] - vec[min_idx];
                    num += 2;
                    vec.erase(vec.begin() + max_idx);
                    vec.erase(vec.begin() + min_idx);
                }
            }
            cout << val << " " << num << endl;
        }

        return 0;
    }
}
#endif

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        ll ans = 0, cnt = 0;
        map<int, int> tmp;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            pq.push(x);
            if (pq.top() < x)
            {
                cnt++;
                ans += x - pq.top();
                if (tmp[pq.top()] > 0)
                {
                    cnt--;
                    tmp[pq.top()]--;
                }
                pq.pop();
                pq.push(x);
                tmp[x]++;
            }
        }
        cout << ans << " " << cnt * 2 << endl;
    }
    return 0;
}
