#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str1;
        string str2;
        cin >> str1;
        cin >> str2;
        int num = 0;
        bool res = true;
        if (str1.length() != str2.length())
        {
            cout << -1 << endl;
            continue;
        }
        
    }
    return 0;
}
