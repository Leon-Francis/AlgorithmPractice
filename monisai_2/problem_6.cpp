#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = str[i] + 3;
        if (str[i] > 'z')
        {
            str[i] = str[i] - 26;
        }
    }
    cout << str;
    return 0;
}
