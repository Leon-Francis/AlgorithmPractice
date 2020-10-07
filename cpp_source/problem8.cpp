#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    char nums1[1000][1000];
    char nums2[1000][1000];
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            nums2[i][j] = '.';
        }
    }
    int k;
    cin >> k;
    char (*currentnum)[1000];
    currentnum = nums1;
    char (*nextnum)[1000];
    nextnum = nums2;
    for (int p = 0; p < k; p++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(currentnum[i][j]=='g')
                {
                    nextnum[i][j] = 'g';
                    if(j - 1 >= 0)
                    {
                        nextnum[i][j - 1] = 'g';
                    }
                    if(i - 1 >= 0)
                    {
                        nextnum[i - 1][j] = 'g';
                    }
                    if(j + 1 < m)
                    {
                        nextnum[i][j + 1] = 'g';
                    }
                    if(i + 1 < n)
                    {
                        nextnum[i + 1][j] = 'g';
                    }
                }
            }
        }
        char(*temp)[1000];
        temp = currentnum;
        currentnum = nextnum;
        nextnum = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << currentnum[i] << endl;
    }
        return 0;
}