#include <iostream>
#include <string>
using namespace std;

#define N 4
#define M 10

struct
{
    string type; /*设备类名*/
    int count;   /*拥有设备台数*/
    int remain;  /*现存的可用设备台数*/
    int address; /*该类设备在设备表中的起始地址*/
} equiptype[N];  /*设备类表定义，假定系统有n个设备类型*/
struct
{
    int number;     /*设备绝对号*/
    bool status;    /*设备好坏状态*/
    bool remain;    /*设备是否已分配*/
    string jobname; /*占有设备的作业名*/
    int lnumber;    /*设备相对号*/
} equipment[M];     /*设备表定义，假定系统有m个设备*/

int equipmentAllocate(string jobName, string equipmentName, int lnumber)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        if (equiptype[i].type == equipmentName)
        {
            break;
        }
    }
    if (equiptype[i].type != equipmentName)
    {
        cout << "不存在这种设备，分配失败" << endl;
        return -1;
    }
    if (equiptype[i].remain <= 0)
    {
        cout << "无可用设备，分配失败" << endl;
        return -1;
    }
    //从设备表中寻找
    int j = 0;
    for (j = equiptype[i].address; j < (equiptype[i].address + equiptype[i].count); j++)
    {
        if (equipment[j].remain == true && equipment[j].status == true)
        {
            break;
        }
    }
    //修改设备表
    equipment[j].jobname = jobName;
    equipment[j].lnumber = lnumber;
    equipment[j].remain = false;
    //修改设备类表
    equiptype[i].remain--;
    //打印控制信息
    cout << "成功将一个" << equipmentName << "分配给" << jobName << endl;
    return equipment[j].number;
}

bool equipmentRecycle(string jobName, string equipmentName)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        if (equiptype[i].type == equipmentName)
        {
            break;
        }
    }
    if (equiptype[i].type != equipmentName)
    {
        cout << "不存在这种设备，回收失败" << endl;
        return false;
    }
    int j = 0;
    bool result = false;
    for (j = equiptype[i].address; j < (equiptype[i].address + equiptype[i].count); j++)
    {
        if (equipment[j].remain == false && equipment[j].jobname == jobName)
        {
            //查找到该作业需要释放的设备
            result = true;
            //修改设备表
            equipment[j].remain = true;
            //修改设备类表
            equiptype[i].remain++;
            //打印控制信息
            cout << "将" << jobName << "所占用的一个" << equipmentName << "回收" << endl;
        }
    }
    if (!result)
    {
        cout << jobName << "没有占用" << equipmentName << "，回收失败" << endl;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    //初始化设备类表和设备表
    equiptype[0].type = "equiptype1";
    equiptype[0].count = 2;
    equiptype[0].remain = 2;
    equiptype[0].address = 0;
    equiptype[1].type = "equiptype2";
    equiptype[1].count = 3;
    equiptype[1].remain = 3;
    equiptype[1].address = 2;
    equiptype[2].type = "equiptype3";
    equiptype[2].count = 2;
    equiptype[2].remain = 3;
    equiptype[2].address = 5;
    equiptype[3].type = "equiptype4";
    equiptype[3].count = 3;
    equiptype[3].remain = 3;
    equiptype[3].address = 7;
    for (int i = 0; i < M; i++)
    {
        equipment[i].number = i;
        equipment[i].status = true;
        equipment[i].remain = true;
    }
    //***********************************
    equipmentAllocate("job1", "equiptype1", 0);
    equipmentAllocate("job1", "equiptype2", 1);
    equipmentAllocate("job1", "equiptype4", 2);
    equipmentAllocate("job1", "equiptype1", 3);
    equipmentAllocate("job2", "equiptype3", 0);
    equipmentAllocate("job2", "equiptype4", 1);
    equipmentRecycle("job1", "equiptype1");
    equipmentRecycle("job1", "equiptype2");
    equipmentRecycle("job1", "equiptype3");
    equipmentAllocate("job2", "equiptype1", 2);
    equipmentAllocate("job2", "equiptype2", 3);
    return 0;
}
