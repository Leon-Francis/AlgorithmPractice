#include<iostream>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        bool res = true;
        string str = to_string(i);
        for (int j = 0; j < str.length()-1; j++)
        {
            if(str[j]>str[j+1])
            {
                res = false;
            }
        }
        if(res)
        {
            result++;
        }
    }
    cout << result;
    return 0;
}
