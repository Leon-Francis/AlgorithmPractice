#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string str1, str2;
    cin >> str1 >> str2;
    if(str1.length() != str2.length())
    {
        cout << "1" << endl;
        return 0;
    }
    if(str1 == str2)
    {
        cout << "2" << endl;
        return 0;
    }
    int dif = 'A' - 'a';
    bool res = true;
    for (int i = 0; i < str1.length(); i++)
    {
        if(abs(str1[i] - str2[i]) != abs(dif) && str1[i] != str2[i])
        {
            res = false;
        }
    }
    if(res)
    {
        cout << "3" << endl;
        return 0;
    }
    cout << "4" << endl;
    return 0;
}
