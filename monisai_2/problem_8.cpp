#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    int res = 0;
    int nums[1000];
    for (int i = 1; i < n; i++)
    {
        nums[i] = 1;
    }
    for (int i = 0; i < m - 2; i++)
    {
        int newnums[1000] = {0};
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n - i + 1; j++)
            {
                newnums[i] += nums[j];
            }
        }
        for (int i = 1; i < n; i++)
        {
            nums[i] = newnums[i];
        }
    }
    for (int i = 1; i < n; i++)
    {
        res = (res + nums[i] * (n - i)) % 10000;
    }
    cout << res << endl;
    return 0;
}
