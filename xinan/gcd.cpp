#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b;
    cout << "请输入a和b: ";
    cin >> a >> b;
    int c;
    c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    cout << "a,b的最大公因数为" << b << endl;
    return 0;
}
