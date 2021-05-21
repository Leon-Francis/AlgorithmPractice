#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> nums(N * 3);
    for (int i = 0; i < N * 3; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += nums[3 * N - 2 * i];
    }
    cout << sum << endl;
    return 0;
}