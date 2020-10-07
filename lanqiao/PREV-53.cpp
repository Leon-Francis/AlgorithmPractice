/*
 * @Author: Leon-Francis
 * @Contact: 15290552788@163.com
 * @Date: 2020-09-22 20:51:28
 * @LastEditTime: 2020-09-23 10:53:15
 * @LastEditors: Leon-Francis
 * @Description: 
 * @FilePath: /cpp/lanqiao/PREV-53.cpp
 * @(C)Copyright 2019-2020, Leon-Francis
 */
#if(0)
#include <iostream>
#include <vector>
using namespace std;

int distribution(vector<vector<int> > nums, vector<vector<int> > room, int stu, int room_minnum)
{
    if (stu == 0)
    {
        return room.size();
    }
    int room_num = 10000;
    for (int i = 0; i < room.size(); i++)
    {
        bool res = true;
        for (int j = 0; res && j < nums.size(); j++)
        {
            for (int k = 0; res && k < room[i].size(); k++)
            {
                if ((nums[j][0] == stu && room[i][k] == nums[j][1]) || (nums[j][1] == stu && room[i][k] == nums[j][0]))
                {
                    res = false;
                }
            }
        }
        if(res)
        {
            room[i].push_back(stu);
            int room_tmp = distribution(nums, room, stu - 1, room);
            if(room_tmp < room_num)
            {
                room_num = room_tmp;
            }
            room[i].pop_back();
        }
    }
    if(room_minnum < room.size() + 1)
    {
        return 10000;
    }
    vector<int> tmp;
    tmp.push_back(stu);
    room.push_back(tmp);
    int room_tmp = distribution(nums, room, stu - 1);
    if (room_tmp < room_num)
    {
        room_num = room_tmp;
    }
    return room_num;
}

int main(int argc, char const *argv[])
{
    int stu_num;
    cin >> stu_num;
    int num;
    cin >> num;
    vector<vector<int> > nums(num);
    vector<vector<int> > room;
    for (int i = 0; i < num; i++)
    {
        int a, b;
        cin >> a >> b;
        nums[i].push_back(a);
        nums[i].push_back(b);
    }
    cout << distribution(nums, room, stu_num) << endl;
    return 0;
}
#endif


#include <cstring>
#include <iostream>
using namespace std;
int rela[105][105];
int stu[105][105]; //保存每个房间的学生的编号
int n, m, cnt = 200;
void dfs(int num, int x)
{ //x表示的是当前操作的学生编号为x，num表示的是当前的房间数量
    if (num >= cnt)
        return; //最优性剪枝，因为当前的回溯的方法以及以及超过之前搜索出来的结果了
    if (x == n + 1)
    { //全部学生已经记录完毕，保存现在的结果，然后return
        cnt = min(cnt, num);
        return;
    }
    int k;
    for (int i = 1; i <= num; i++)
    {
        k = 0; //从房间i的第一个学生开始检查
               //stu[i][k]表示房间i第k个学生的编号
        while (stu[i][k] && !rela[stu[i][k]][x])
            k++; //检查房间i中的学生与x是否冲突
        if (stu[i][k] == 0)
        {                  //满足条件，位置k为空位，说明x可以放入房间i中
            stu[i][k] = x; //x放入
            dfs(num, x + 1);
            stu[i][k] = 0; //回溯，x取出
        }
    }
    stu[num + 1][0] = x; //增加房间，将x加入
    dfs(num + 1, x + 1); //如果所有房间都不满足，增加房间
    stu[num + 1][0] = 0; // 回溯
}
int main()
{
    cin >> n >> m;
    int a, b;
    memset(rela, 0, sizeof(rela));
    memset(stu, 0, sizeof(stu));
    while (m--)
    {
        cin >> a >> b;
        rela[a][b] = rela[b][a] = 1;
    }
    dfs(1, 1);
    cout << cnt << endl;
}
