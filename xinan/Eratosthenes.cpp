#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout << "请输入输出素数的范围n(0,65536):";
    cin >> n;
    int nums[65536] = {1, 1};
    int p = int(sqrt(n));
    for (int i = 2; i <= p; i++)
    {
        bool prime = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
            }
        }
        if (prime)
        {
            for (int j = 2; i * j <= n; j++)
            {
                nums[i * j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (nums[i] == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}
