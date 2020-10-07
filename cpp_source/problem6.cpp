#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int i = 0;
    bool result[4] = {false, false, false, false};
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            break;
        }
        result[0] = true;
    }
    for (; i < str.length(); i++)
    {
        if (!((str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')))
        {
            break;
        }
        result[1] = true;
    }
    for (; i < str.length(); i++)
    {
        if ((str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'))
        {
            break;
        }
        result[2] = true;
    }
    for (; i < str.length(); i++)
    {
        if (!((str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')))
        {
            break;
        }
        result[3] = true;
    }
    if(result[0]&&result[1]&&result[2]&&result[3])
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}