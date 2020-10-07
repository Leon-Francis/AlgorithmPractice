#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

double Distance(int nums[1000][3], int a, int b)
{
    return sqrt(pow((nums[a][0] - nums[b][0]), 2) + pow((nums[a][1] - nums[b][1]), 2)) + pow((nums[a][2] - nums[b][2]), 2);
}

int main()
{
    int n;
    cin >> n;
    int nums[1000][3];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> nums[i][j];
        }
    }
    double result = 0;
    int setvil[1000];
    setvil[0] = 1;
    int setnum = 1;
    int unsetvil[1000];
    int unsetnum = n - 1;
    for (int i = 0; i < unsetnum; i++)
    {
        unsetvil[i] = i + 2;
    }
    while (unsetnum != 0)
    {
        int begin = setvil[0];
        int end = unsetvil[0];
        double mindistance = Distance(nums, setvil[0], unsetvil[0]);
        for (int i = 0; i < setnum; i++)
        {
            for (int j = 0; j < unsetnum; j++)
            {
                double dis = Distance(nums, setvil[i], unsetvil[j]);
                if (dis < mindistance)
                {
                    begin = setvil[i];
                    end = unsetvil[j];
                    mindistance = Distance(nums, setvil[i], unsetvil[j]);
                }
            }
        }
        result += mindistance;
        setvil[setnum] = end;
        setnum++;
        int t = 0;
        for (t = 0; t < unsetnum; t++)
        {
            if (unsetvil[t] == end)
            {
                break;
            }
        }
        for (int i = t; i < unsetnum - 1; i++)
        {
            unsetvil[t] = unsetvil[t + 1];
        }
        unsetnum--;
    }
    cout << fixed << setprecision(2) << result << endl;
    return 0;
}