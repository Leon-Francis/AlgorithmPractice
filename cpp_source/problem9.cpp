#include<iostream>
#include<math.h>
using namespace std;

void func(int n, int i, int &result)
{
    result = (result + 1) % 10000;
    if (abs(n - i) <= 1)
    {
        return;
    }
    for (int j = 1; j < abs(n - i); j++)
    {
        func(i, j, result);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        func(n, i, result);
    }
    cout << result << endl;
    return 0;
}
