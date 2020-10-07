#include<iostream>
using namespace std;

void func(int nums[], int begin, int num, int n)
{
    if(num==0)
    {
        return;
    }
    int max = nums[begin];
    int index = begin;
    for (int i = begin + 1; i <= n - num; i++)
    {
        if(max < nums[i])
        {
            max = nums[i];
            index = i;
        }
    }
    cout << max << " ";
    func(nums, index + 1, num - 1, n);
    return;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int nums[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    func(nums, 0, m, n);
    return 0;
}
