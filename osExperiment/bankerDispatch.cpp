#include <iostream>
using namespace std;

#define M 5
#define N 3

bool bankerDispatch(int need[M][N], int allocation[M][N], int available[N], int n, int request[N])
{
    for (int i = 0; i < N; i++)
    {
        if (request[i] > need[n][i])
        {
            cout << "申请资源大于需要资源，出错" << endl;
            return false;
        }
        if (request[i] > available[i])
        {
            cout << "申请资源大于可用资源，出错" << endl;
            return false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        available[i] -= request[i];
        allocation[n][i] += request[i];
        need[n][i] -= request[i];
    }
    int work[N];
    for (int i = 0; i < N; i++)
    {
        work[i] = available[i];
    }
    bool finish[M] = {false, false, false, false, false};
    int seq[M];
    bool status = false;
    for (int i = 0; i < M; i++)
    {
        status = false;
        for (int j = 0; j < M; j++)
        {
            if (finish[j] == false)
            {
                status = true;
                for (int t = 0; t < N; t++)
                {
                    if (work[t] < need[j][t])
                    {
                        status = false;
                    }
                }
                if (status)
                {
                    for (int t = 0; t < N; t++)
                    {
                        work[t] += allocation[j][t];
                    }
                    seq[i] = j;
                    finish[j] = true;
                    break;
                }
            }
        }
        if (!status)
        {
            cout << "不存在安全序列，不能进行分配" << endl;
            for (int t = 0; t < N; t++)
            {
                available[t] += request[t];
                allocation[n][t] -= request[t];
                need[n][t] += request[t];
            }
            return false;
        }
    }
    cout << "存在安全序列为： ";
    for (int i = 0; i < M; i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl
         << "故可以进行分配" << endl;
    cout << "此时剩余的资源数目为： ";
    for (int i = 0; i < N; i++)
    {
        cout << available[i] << " ";
    }
    cout << endl;
    return true;
}

int main(int argc, char const *argv[])
{
    int max[M][N] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int available[N] = {10, 5, 7};
    int allocation[M][N] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int need[M][N];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    int n = 0;
    int request[N] = {0};
    while (true)
    {
        cout << "输入申请资源的进程号（0-4），输入-1退出： ";
        cin >> n;
        if (n == -1)
        {
            return 0;
        }
        else
        {
            cout << "输入申请分配的资源数： ";
            for (int i = 0; i < N; i++)
            {
                cin >> request[i];
            }
            bankerDispatch(need, allocation, available, n, request);
        }
    }
}