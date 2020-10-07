#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nums[34];
    nums[0] = 1;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << nums[j] << " ";
        }
        cout << endl;
        nums[i + 1] = 1;
        for (int j = i; j >= 1; j--)
        {
            nums[j] += nums[j - 1];
        }
    }
    return 0;
}