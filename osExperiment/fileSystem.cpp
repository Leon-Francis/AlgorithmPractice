#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;

typedef struct directoryNode
{
    int tag = 0; /*0-dump node,1-real node*/
    string name;
    int type;                        /*0-directory file 1-comman file*/
    struct nomalFile *p_nomFile;     /*point to comman file */
    struct directoryFile *p_dirFile; /*point to dirctory file*/
} * directoryNodePointer;

struct nomalFile
{
    int size; /*file size*/
};

struct directoryFile
{ /*directory file composed by a node array*/
    /*nodes*/
    struct directoryNode nodesArray[10];
};
/*initializing file system*/

void deleteAll(directoryNodePointer p)
{
    for (int i = 0; i < 10; i++)
    {
        if(p->p_dirFile->nodesArray[i].tag == 1)
        {
            if(p->p_dirFile->nodesArray[i].type == 1)
            {
                delete p->p_dirFile->nodesArray[i].p_nomFile;
                p->p_dirFile->nodesArray[i].tag = 0;
            }
            else
            {
                deleteAll(&(p->p_dirFile->nodesArray[i]));
            }
        }
    }
    delete p->p_dirFile;
    p->tag = 0;
}


int main(int argc, char const *argv[])
{
    /*系统初值*/
    /*创建根目录*/
    directoryNodePointer root = new directoryNode;
    root->tag = 1;
    root->name = "";
    root->type = 0;
    root->p_dirFile = new directoryFile;
    directoryNodePointer path[10];
    path[0] = root;
    int pathNum = 1;
    /*交互式系统*/
    while (true)
    {
        /*输出当前所在的目录*/
        cout << "< ";
        if (pathNum == 1)
        {
            cout << "/";
        }
        else
        {
            for (int i = 1; i < pathNum; i++)
            {
                cout << "/" << path[i]->name;
            }
        }
        cout << " >";
        //输出提示符
        cout << " # ";
        //接收操作
        string op;
        cin >> op;
        if (op == "CD" || op == "cd")
        {
            string dirName;
            cin >> dirName;
            if (dirName == "..")
            {
                if (pathNum != 1)
                {
                    pathNum--;
                }
            }
            else
            {
                //查询此子目录
                bool result = false;
                for (int i = 0; i < 10; i++)
                {
                    if (path[pathNum - 1]->p_dirFile->nodesArray[i].tag == 1 &&
                        path[pathNum - 1]->p_dirFile->nodesArray[i].type == 0 &&
                        path[pathNum - 1]->p_dirFile->nodesArray[i].name == dirName)
                    {
                        //找到了,切换目录
                        result = true;
                        path[pathNum] = &(path[pathNum - 1]->p_dirFile->nodesArray)[i];
                        pathNum++;
                    }
                }
                if (!result)
                {
                    //没有找到，输出错误信息
                    cout << "在当前目录中并未找到此子目录，请重新输入" << endl;
                    continue;
                }
            }
        }
        else if (op == "CREATE" || op == "create")
        {
            string fileName;
            int fileSize;
            cin >> fileName >> fileSize;
            int result = 0; //0代表已满，1代表重名，2代表找到
            directoryNodePointer p = NULL;
            //首先查找是否已满或者重名
            for (int i = 0; i < 10; i++)
            {
                if (path[pathNum - 1]->p_dirFile->nodesArray[i].tag == 1)
                {
                    if (path[pathNum - 1]->p_dirFile->nodesArray[i].name == fileName)
                    {
                        //重名
                        cout << "当前目录下已有此文件，请重新输入" << endl;
                        result = 1;
                        break;
                    }
                }
                else
                {
                    if (result != 2)
                    {
                        p = &(path[pathNum - 1]->p_dirFile->nodesArray[i]);
                        result = 2;
                    }
                }
            }
            if (result == 1)
            {
                continue;
            }
            if (result == 0)
            {
                cout << "当前目录下空间已满，请重新输入" << endl;
                continue;
            }
            //找到,分配文件
            p->tag = 1;
            p->name = fileName;
            p->type = 1;
            p->p_nomFile = new nomalFile;
            p->p_nomFile->size = fileSize;
            continue;
        }
        else if (op == "DEL" || op == "del")
        {
            string fileName;
            cin >> fileName;
            bool result = false; //false表示未找到
            //首先查找
            for (int i = 0; i < 10; i++)
            {
                if (path[pathNum - 1]->p_dirFile->nodesArray[i].tag == 1)
                {
                    if (path[pathNum - 1]->p_dirFile->nodesArray[i].name == fileName)
                    {
                        if (path[pathNum - 1]->p_dirFile->nodesArray[i].type == 0)
                        {
                            //是目录文件，出错
                            result = true;
                            cout << "该文件是目录文件，不能使用DEL删除，请重新输入" << endl;
                            break;
                        }
                        //找到,将其删除
                        delete path[pathNum - 1]->p_dirFile->nodesArray[i].p_nomFile;
                        path[pathNum - 1]->p_dirFile->nodesArray[i].tag = 0;
                        result = true;
                        break;
                    }
                }
            }
            if (!result)
            {
                //未找到，输出错误信息
                cout << "在当前目录中并未找到此文件，请重新输入" << endl;
            }
            continue;
        }
        else if (op == "LSALL" || op == "lsall")
        {
            directoryNodePointer nodeStack[20];
            nodeStack[0] = root;
            int nodeNum = 1;
            string messageStack[20];
            messageStack[0] = "/";
            //广度优先遍历
            while (nodeNum != 0)
            {
                //从堆栈中取出元素
                directoryNodePointer p = nodeStack[nodeNum - 1];
                string preMessage = messageStack[nodeNum - 1];
                nodeNum--;
                for (int i = 0; i < 10; i++)
                {
                    if (p->p_dirFile->nodesArray[i].tag == 1)
                    {
                        //找到文件
                        cout << preMessage << p->p_dirFile->nodesArray[i].name << endl;
                        if (p->p_dirFile->nodesArray[i].type == 0)
                        {
                            //是目录文件，入栈
                            nodeStack[nodeNum] = &(p->p_dirFile->nodesArray[i]);
                            messageStack[nodeNum] = preMessage + p->p_dirFile->nodesArray[i].name + "/";
                            nodeNum++;
                        }
                    }
                }
            }
        }
        else if (op == "MD" || op == "md")
        {
            string dirName;
            cin >> dirName;
            int result = 0; //0代表已满，1代表重名，2代表找到
            directoryNodePointer p = NULL;
            //首先查找是否已满或者重名
            for (int i = 0; i < 10; i++)
            {
                if (path[pathNum - 1]->p_dirFile->nodesArray[i].tag == 1)
                {
                    if (path[pathNum - 1]->p_dirFile->nodesArray[i].name == dirName)
                    {
                        //重名
                        cout << "当前目录下已有此目录，请重新输入" << endl;
                        result = 1;
                        break;
                    }
                }
                else
                {
                    if (result != 2)
                    {
                        p = &(path[pathNum - 1]->p_dirFile->nodesArray[i]);
                        result = 2;
                    }
                }
            }
            if (result == 1)
            {
                continue;
            }
            if (result == 0)
            {
                cout << "当前目录下空间已满，请重新输入" << endl;
                continue;
            }
            //找到,分配目录项
            p->tag = 1;
            p->name = dirName;
            p->type = 0;
            p->p_dirFile = new directoryFile;
            continue;
        }
        else if (op == "RD" || op == "rd")
        {
            string dirName;
            cin >> dirName;
            bool result = false; //false表示未找到
            //首先查找
            for (int i = 0; i < 10; i++)
            {
                if (path[pathNum - 1]->p_dirFile->nodesArray[i].tag == 1)
                {
                    if (path[pathNum - 1]->p_dirFile->nodesArray[i].name == dirName)
                    {
                        if (path[pathNum - 1]->p_dirFile->nodesArray[i].type == 1)
                        {
                            //是普通文件，出错
                            result = true;
                            cout << "该文件是常规文件，不能使用RD删除，请重新输入" << endl;
                            break;
                        }
                        //找到,判断其是否为空目录；
                        directoryNodePointer p = &(path[pathNum - 1]->p_dirFile->nodesArray[i]);
                        bool empty = true;
                        for (int j = 0; j < 10; j++)
                        {
                            if (p->p_dirFile->nodesArray[j].tag == 1)
                            {
                                empty = false;
                                break;
                            }
                        }
                        if(empty)
                        {
                            //为空，直接删除
                            delete p->p_dirFile;
                            p->tag = 0;
                            result = true;
                        }
                        else
                        {
                            //不为空，递归删除
                            cout << "该目录不为空，是否删除其中的所有文件（y or n）? ";
                            string choice;
                            cin >> choice;
                            result = true;
                            while(choice != "y" && choice != "n")
                            {
                                cout << "输入错误，请重新输入（y or n）?";
                            }
                            if(choice == "n")
                            {
                                break;
                            }
                            else
                            {
                                //递归删除
                                deleteAll(p);
                            } 
                        }
                    }
                }
            }
            if (!result)
            {
                //未找到，输出错误信息
                cout << "在当前目录中并未找到此目录，请重新输入" << endl;
            }
        }
        else if(op == "EXIT" || op == "exit")
        {
            return 0;
        }
        else
        {
            cout << "无效指令，请重新输入" << endl;
        }
    }
    return 0;
}
