#include <iostream>
#include <string>
using namespace std;

#define RAMSIZE 128

typedef struct JCB
{
    int name = 0;
    int startAddr = 0;
    int size = 0;
    struct JCB *next = NULL;
} * JCBPointer;

bool ramAllocate(JCBPointer JCBHead, int freeSpaceForm[20][3], int name, int size)
{
    int i = 0;
    while (true)
    {
        if(freeSpaceForm[i][2] == 0)
        {
            cout << "剩余内存不足，无法分配" << endl;
            return false;
        }
        if(freeSpaceForm[i][1] < size)
        {
            i++;
            continue;
        }
        JCBPointer temp = new JCB;
        temp->startAddr = freeSpaceForm[i][0];
        temp->name = name;
        temp->size = size;
        temp->next = JCBHead->next;
        JCBHead->next = temp;
        freeSpaceForm[i][0] += size;
        freeSpaceForm[i][1] -= size;
        cout << "为作业" << name << "成功分配" << size << "K大小的空间" << endl;
        if(freeSpaceForm[i][1] == 0) //如果表项大小为0则将表项删除
		{
			freeSpaceForm[i][2] = 0;
			i++;
			while(freeSpaceForm[i][2] != 0)
			{
				for (int j = 0; j < 3; j++)
				{
					freeSpaceForm[i - 1][j] = freeSpaceForm[i][j];
				}
				freeSpaceForm[i][2] = 0;
				i++;
			}
		}
		return true;
    }
}

bool ramRecycle(JCBPointer JCBHead, int freeSpaceForm[20][3], int name)
{
	//首先找到作业控制块
	JCBPointer p = JCBHead;
	while (p != NULL && p->name != name)
	{
		p = p->next;
	}
	if(p == NULL)
	{
		cout << "查找失败，当前作业队列为空或无此作业" << endl;
		return false;
	}
	//然后分三种情况对空闲分区表进行修改
	int preBlock = 0;
	bool pre = false;
	int backBlock = 0;
	bool back = false;
	while (freeSpaceForm[preBlock][2] != 0)
	{
		if((freeSpaceForm[preBlock][0] + freeSpaceForm[preBlock][1]) == p->startAddr)
		{
			pre = true;
			break;
		}
		preBlock++;
	}
	while (freeSpaceForm[backBlock][2] != 0)
	{
		if (freeSpaceForm[backBlock][0] == (p->startAddr + p->size))
		{
			back = true;
			break;
		}
		backBlock++;
	}
	if(pre && back)
	{
		freeSpaceForm[preBlock][1] += p->size + freeSpaceForm[backBlock][1];
		freeSpaceForm[backBlock][2] = 0;
		backBlock++;
		while (freeSpaceForm[backBlock][2] != 0)
		{
			for (int j = 0; j < 3; j++)
			{
				freeSpaceForm[backBlock - 1][j] = freeSpaceForm[backBlock][j];
			}
			freeSpaceForm[backBlock][2] = 0;
			backBlock++;
		}
	}
	else if(pre)
	{
		freeSpaceForm[preBlock][1] += p->size;
	}
	else if(back)
	{
		freeSpaceForm[backBlock][0] -= p->size;
		freeSpaceForm[backBlock][1] += p->size;
	}
	else
	{
		int i = 0;
		while(freeSpaceForm[i][2] != 0)
		{
			i++;
		}
		freeSpaceForm[i][0] = p->startAddr;
		freeSpaceForm[i][1] = p->size;
		freeSpaceForm[i][2] = 1;
		//将新建的标目放于合适位置
		while(freeSpaceForm[i-1][0] > freeSpaceForm[i][0])
		{
			for (int j = 0; j < 3; j++)
			{
				int temp = freeSpaceForm[i - 1][j];
				freeSpaceForm[i - 1][j] = freeSpaceForm[i][j];
				freeSpaceForm[i][j] = temp;
			}
			i--;
		}
	}
	//输出信息
	cout << "将作业" << p->name << "删除，释放" << p->size << "K大小的内存" << endl;
	//将p从链表中删除
	JCBPointer prep = JCBHead;
	while (prep->next != p)
	{
		prep = prep->next;
	}
	prep->next = prep->next->next;
	//回收内存
	delete p;
	return true;
}

void printForm(int freeSpaceForm[20][3])
{
	int i = 0;
	if(freeSpaceForm[i][2] == 0)
	{
		cout << "空闲分区表中无内容" << endl;
		return;
	}
	cout << "此时空闲分区表为" << endl;
	cout << "起址  长度  状态  " << endl;
	while(freeSpaceForm[i][2] != 0)
	{
		cout << freeSpaceForm[i][0] << "     " << freeSpaceForm[i][1] << "     " << freeSpaceForm[i][2] << endl;
		i++;
	}
}

int main(int argc, char const *argv[])
{
    JCBPointer JCBHead = new JCB;
    int freeSpaceForm[20][3] = {0};
    //将空闲分区表和作业队列赋初值为题目中所给状态
    JCBPointer p = new JCB;
    p->name = 1;
    p->startAddr = 5;
    p->size = 5;
    JCBHead->next = p;
    JCBPointer temp = new JCB;
    temp->name = 2;
    temp->startAddr = 26;
    temp->size = 6;
    p->next = temp;
    p = temp;
    temp = new JCB;
    temp->name = 3;
    temp->startAddr = 10;
    temp->size = 4;
    p->next = temp;
    freeSpaceForm[0][0] = 14;
    freeSpaceForm[0][1] = 12;
    freeSpaceForm[0][2] = 1;
    freeSpaceForm[1][0] = 32;
    freeSpaceForm[1][1] = 96;
    freeSpaceForm[1][2] = 1;
    //**************************************
	cout << "初始状态";
	printForm(freeSpaceForm);
	ramAllocate(JCBHead, freeSpaceForm, 4, 6);
	printForm(freeSpaceForm);
	ramRecycle(JCBHead, freeSpaceForm, 3);
	printForm(freeSpaceForm);
	ramRecycle(JCBHead, freeSpaceForm, 2);
	printForm(freeSpaceForm);
	return 0;
}