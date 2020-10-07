#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    for (int i = 100; i < 1000; i++)
    {
        int num[3];
        num[2] = i % 10;
        num[1] = (i / 10) % 10;
        num[0] = i / 100;
        if (i == num[0] * num[0] * num[0] + num[1] * num[1] * num[1] + num[2] * num[2] * num[2])
        {
            cout << i << endl;
        }
    }
    return 0;
}
