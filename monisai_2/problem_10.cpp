#include <iostream>
using namespace std;

bool compatible(int nums[1000][3], int a, int b)
{
    int x = nums[a][0] - nums[b][0];
    int y = nums[a][1] - nums[b][1];
    int d = nums[a][2] + nums[b][2];
    if (x * x + y * y >= d * d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void backtrack(int t, int n, int nums[1000][3], int results[1000], int &max)
{
    if (t == n)
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (results[i] == 1)
            {
                temp += nums[i][2] * nums[i][2];
            }
        }
        if (temp > max)
        {
            max = temp;
        }
        return;
    }
    bool comp = true;
    for (int i = 0; i < t; i++)
    {
        if (results[i] == 1)
        {
            if (!compatible(nums, i, t))
            {
                comp = false;
            }
        }
    }
    if (comp)
    {
        results[t] = 1;
        backtrack(t + 1, n, nums, results, max);
        results[t] = 0;
        backtrack(t + 1, n, nums, results, max);
    }
    else
    {
        results[t] = 0;
        backtrack(t + 1, n, nums, results, max);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int nums[1000][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> nums[i][j];
        }
    }
    int results[1000] = {0};
    int max = 0;
    backtrack(0, n, nums, results, max);
    cout << max << endl;
    return 0;
}