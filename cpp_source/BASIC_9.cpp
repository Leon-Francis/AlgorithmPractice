#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    //先输出五位数
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int t = 0; t < 10; t++)
            {
                if (2 * i + 2 * j + t == n)
                {
                    cout << i << j << t << j << i << endl;
                }
            }
        }
    }
    //再输出六位数
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int t = 0; t < 10; t++)
            {
                if (2 * i + 2 * j + 2 * t == n)
                {
                    cout << i << j << t << t << j << i << endl;
                }
            }
        }
    }
    return 0;
}
