#include <iostream>
using namespace std;

void PrintResult(int form[7][13], int W[7])
{
    int j = 12;
    for (int i = 6; i > 0; i--)
    {
        if(form[i][j]==form[i-1][j])
        {
            continue;
        }
        cout << 7 - i << " ";
        j = j - W[7 - i];
    }
}

int main(int argc, char const *argv[])
{
    int W[7] = {0, 3, 5, 2, 6, 4, 7};
    int P[7] = {0, 4, 7, 5, 11, 3, 8};
    int form[7][13] = {};
    for (int j = 0; j <= 12; j++)  //为form数组第一行赋初值
    {
        if (W[6] > j)
        {
            form[1][j] = 0;
        }
        else
        {
            form[1][j] = P[6];
        }
    }
    for (int i = 2; i <= 6; i++)    //填form数组的第i行
    {
        for (int j = 0; j <= 12; j++)   //填form数组第j列
        {
            if (W[7 - i] > j)           //wi>j的情况
            {
                form[i][j] = form[i - 1][j];      
            }
            else                        //wi<=j的情况
            {
                int temp = P[7 - i] + form[i - 1][j - W[7 - i]];
                form[i][j] = temp > form[i - 1][j] ? temp : form[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 0; j <= 12; j++)
        {
            cout << form[i][j] << " ";
        }
        cout << endl;
    }
    PrintResult(form, W);
    return 0;
}
