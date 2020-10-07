#include <iostream>
#include <string>
using namespace std;
#define PROCESSNUM 5

typedef struct PCB
{
    string name = "";
    struct PCB *next = NULL;
    int reqTime = 0;
    int exeTime = 0;
    char status = 'R';
} * PCBPointer;

void runProcess(PCBPointer PCBHead, int time)
{
    PCBPointer p = PCBHead;
    while (PCBHead->next != NULL)
    {
        time++;
        p = p->next;
        p->exeTime++;
        cout << time << "时刻" << p->name << "进程执行1个时间片" << endl;
        if (p->exeTime == p->reqTime)
        {
            cout << time << "时刻" << p->name << "进程执行完毕，被移出队列" << endl;
            p->status = 'E';
            if (p->next == p) //最后一个进程
            {
                PCBHead->next = NULL;
            }
            else //剔除进程
            {
                PCBPointer pre = PCBHead->next;
                if(p == PCBHead->next) // 第一个进程
                {
                    PCBHead->next = p->next;
                }
                while (pre->next != p)
                {
                    pre = pre->next;
                }
                pre->next = pre->next->next;
            }
        }
        cout << time << "时刻" << "执行后的进程控制块状态为：" << endl;
        PCBPointer t = PCBHead;
        if (t->next == NULL)
        {
            cout << "无进程" << endl;
        }
        else
        {
            do
            {
                t = t->next;
                cout << t->name << " 指向" << t->next->name << "的指针 " << t->reqTime << " " << t->exeTime << " " << t->status << endl;
            } while (t->next != PCBHead->next);
        }
    }
}

int main(int argc, char const *argv[])
{
    int time = 0;
    PCBPointer PCBHead = new PCB;
    PCBPointer p = PCBHead;
    cout << "输入每个进程的要求运行时间" << endl;
    for (int i = 0; i < PROCESSNUM; i++)
    {
        PCBPointer temp = new PCB;
        temp->name = "Q" + to_string(i + 1);
        cin >> temp->reqTime;
        temp->exeTime = 0;
        temp->status = 'R';
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
    p->next = PCBHead->next;
    cout << "初始状态的进程控制块状态为" << endl;
    p = PCBHead;
    if (p->next == NULL)
    {
        cout << "无进程" << endl;
    }
    else
    {
        do
        {
            p = p->next;
            cout << p->name << " 指向" << p->next->name << "的指针 " << p->reqTime << " " << p->exeTime << " " << p->status << endl;
        } while (p->next != PCBHead->next);
    }
    runProcess(PCBHead, time);
    return 0;
}
