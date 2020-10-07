#include<iostream>
using namespace std;
int main()
{
    int n = 1200000;
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        if(n%i==0)
        {
            result++;
        }
    }
    cout << result;
    return 0;
}