#include <iostream>
using namespace std;

void backtrack(int x0, int y0, int x, int y, int X, int Y, int &result)
{
    if (y0 > y)
    {
        return;
    }
    if (y0 == y)
    {
        if (x0 == x)
        {
            result++;
        }
        return;
    }
    if (x0 - 2 >= 1)
    {
        backtrack(x0 - 2, y0 + 1, x, y, X, Y, result);
    }
    if (x0 - 1 >= 1)
    {
        backtrack(x0 - 1, y0 + 2, x, y, X, Y, result);
    }
    if (x0 + 1 <= X)
    {
        backtrack(x0 + 1, y0 + 2, x, y, X, Y, result);
    }
    if (x0 + 2 <= X)
    {
        backtrack(x0 + 2, y0 + 1, x, y, X, Y, result);
    }
}

int main(int argc, char const *argv[])
{
    int X = 9;
    int Y = 10; //棋盘大小
    int x0 = 2;
    int y0 = 1; //起始位置
    int x = 7;
    int y = 8;      //目标位置
    int result = 0; //方法数
    backtrack(x0, y0, x, y, X, Y, result);
    cout << result << endl;
    return 0;
}
