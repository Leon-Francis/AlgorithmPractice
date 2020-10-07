#include <iostream>
#include <string>
using namespace std;

#define RAMSIZE 64
#define TYPEDRIVENUM 4
#define PRINTNUM 2

typedef struct JCB
{
    string name = "";
    double size = 0;
    int printNeeds = 0;
    int tapeDriveNeeds = 0;
    double executeTime = 0;
    double waitTime = 0;
    struct JCB *next = NULL;
} * JCBPointer;

bool dispatch(JCBPointer JCBWaitHead, JCBPointer JCBExecuteHead, int &tapedrive, int &print, double &ramSize, double runTime)
{
    if (JCBWaitHead->next == NULL)
    {
        return true;
    }
    bool status = false;
    while (true)
    {
        double pirority = 0;
        JCBPointer pirPointer = NULL;
        JCBPointer p = JCBWaitHead;
        while (p->next != NULL)
        {
            p = p->next;
            if (p->size <= ramSize && p->tapeDriveNeeds <= tapedrive && p->printNeeds <= print)
            {
                double temp = (p->waitTime + p->executeTime) / p->executeTime;
                if (temp > pirority)
                {
                    pirPointer = p;
                    pirority = temp;
                    status = true;
                }
            }
        }
        if (pirPointer == NULL)
        {
            break;
        }
        else
        {
            p = JCBWaitHead;
            while (p->next != pirPointer)
            {
                p = p->next;
            }
            p->next = p->next->next;
            pirPointer->next = JCBExecuteHead->next;
            JCBExecuteHead->next = pirPointer;
            ramSize -= pirPointer->size;
            tapedrive -= pirPointer->tapeDriveNeeds;
            print -= pirPointer->printNeeds;
            cout << runTime << "时刻发生调度，将" << pirPointer->name << "作业调入内存" << endl;
        }
    }
    return status;
}

void execute(JCBPointer JCBWaitHead, JCBPointer JCBExecuteHead, double &runTime, int &tapedrive, int &print, double &ramSize)
{
    JCBPointer p = JCBExecuteHead;
    JCBPointer timeShortest = NULL;
    double time = 10000;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->executeTime < time)
        {
            timeShortest = p;
            time = p->executeTime;
        }
    }
    p = JCBExecuteHead;
    while (p->next != timeShortest)
    {
        p = p->next;
    }
    p->next = p->next->next;
    ramSize += timeShortest->size;
    tapedrive += timeShortest->tapeDriveNeeds;
    print += timeShortest->printNeeds;
    runTime += time;
    p = JCBWaitHead;
    while (p->next != NULL)
    {
        p = p->next;
        p->waitTime += time;
    }
    p = JCBExecuteHead;
    while (p->next != NULL)
    {
        p = p->next;
        p->executeTime -= time;
        p->waitTime += time;
    }
    cout << runTime << "时刻作业" << timeShortest->name << "执行完毕" << endl;
    delete timeShortest;
}

void printStatus(JCBPointer JCBWaitHead, JCBPointer JCBExecuteHead, double runTime)
{
    cout << runTime << "时刻处于后备队列的作业状态：" << endl;
    JCBPointer p = JCBWaitHead;
    if (p->next == NULL)
    {
        cout << "无作业" << endl;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
            cout << p->name << " " << p->size << " " << p->tapeDriveNeeds << " " << p->printNeeds << " " << p->executeTime << " " << p->waitTime << endl;
        }
    }
    cout << runTime << "时刻处于执行队列的作业状态：" << endl;
    p = JCBExecuteHead;
    if (p->next == NULL)
    {
        cout << "无作业" << endl;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
            cout << p->name << " " << p->size << " " << p->tapeDriveNeeds << " " << p->printNeeds << " " << p->executeTime << " " << p->waitTime << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    double ramSize = RAMSIZE;
    int tapeDrive = TYPEDRIVENUM;
    int print = PRINTNUM;
    JCBPointer JCBWaitHead = new JCB;
    JCBPointer JCBExecuteHead = new JCB;
    JCBPointer p = JCBWaitHead;
    double runTime = 0;
    cout << "输入作业个数" << endl;
    int n;
    cin >> n;
    cout << "按作业名称 作业大小 需要磁带机数目 需要打印机数目 执行时间 等待时间的格式输入" << endl;
    for (int i = 0; i < n; i++)
    {
        JCBPointer temp = new JCB;
        cin >> temp->name;
        cin >> temp->size;
        cin >> temp->tapeDriveNeeds;
        cin >> temp->printNeeds;
        cin >> temp->executeTime;
        cin >> temp->waitTime;
        p->next = temp;
        p = p->next;
    }
    while (JCBWaitHead->next != NULL || JCBExecuteHead->next != NULL)
    {
        dispatch(JCBWaitHead, JCBExecuteHead, tapeDrive, print, ramSize, runTime);
        execute(JCBWaitHead, JCBExecuteHead, runTime, tapeDrive, print, ramSize);
        printStatus(JCBWaitHead, JCBExecuteHead, runTime);
    }
    return 0;
}
