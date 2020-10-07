#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n = 2019;
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        string num = "";
        num = to_string(i);
        for (int j = 0; j < num.length(); j++)
        {
            if(num[j]=='9')
            {
                result++;
                break;
            }
        }
    }
    cout << result;
    return 0;
}