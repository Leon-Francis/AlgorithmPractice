#include<iostream>
using namespace std;
int main()
{
    int n;
    int nums[10000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int result = 0;
    for (int i = 1; i < n - 1; i++)
    {
        bool left = false;
        bool right = false;
        for (int j = 0; j < i; j++)
        {
            if(nums[j]<nums[i])
            {
                left = true;
                break;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if(nums[j]>nums[i])
            {
                right = true;
                break;
            }
        }
        if(left&&right)
        {
            result++;
        }
    }
    cout << result;
    return 0;
}