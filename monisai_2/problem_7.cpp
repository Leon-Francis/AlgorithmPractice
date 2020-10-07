#include <iostream>
using namespace std;

void CreatMatrix(int nums[1000][1000], int n, int m, int begin, int num)
{
    if (n - begin <= 0 || m - begin <= 0)
    {
        return;
    }
    for (int i = begin; i < m; i++)
    {
        nums[begin][i] = num;
        num++;
    }
    for (int i = begin + 1; i < n; i++)
    {
        nums[i][m - 1] = num;
        num++;
    }
    if (n - begin == 1 || m - begin == 1)
    {
        return;
    }
    for (int i = m - 2; i >= begin; i--)
    {
        nums[n - 1][i] = num;
        num++;
    }
    for (int i = n - 2; i > begin; i--)
    {
        nums[i][begin] = num;
        num++;
    }
    CreatMatrix(nums, n - 1, m - 1, begin + 1, num);
}

int main(int argc, char const *argv[])
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    static int nums[1000][1000];
    CreatMatrix(nums, n, m, 0, 1);
    cout << nums[r-1][c-1] << endl;
    return 0;
}
