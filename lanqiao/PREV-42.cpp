/*** 
 * @Author: Leon-Francis
 * @Date: 2021-04-08 19:54:01
 * @Contact: leon_francis@163.com
 * @LastEditTime: 2021-04-08 20:12:26
 * @LastEditors: Leon-Francis
 * @Description: 九宫幻方
 * @FilePath: /AlgorithmPractice/lanqiao/PREV-42.cpp
 * @(C)Copyright 2020-2021, Leon-Francis
 */
#include <iostream>
using namespace std;
int cube[8][3][3] = {{{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
                     {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
                     {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
                     {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
                     {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
                     {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
                     {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
                     {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}};

bool is_sat(int cube_a[3][3], int cube_b[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (cube_a[i][j] != 0 && cube_a[i][j] != cube_b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int new_cube[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> new_cube[i][j];
        }
    }
    int index = -1;
    for (int i = 0; i < 8; i++)
    {
        if(index == -1)
        {
            if(is_sat(new_cube, cube[i]))
            {
                index = i;
            }
        }
        else
        {
            if(is_sat(new_cube, cube[i]))
            {
                cout << "Too Many" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << cube[index][i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//正确