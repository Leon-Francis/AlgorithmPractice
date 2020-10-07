#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int b, n, m;
    cout << "请输入b,n,m: ";
    cin >> b >> n >> m;
    int r;
    int res = 1;
    while (n != 0)
    {
        r = n % 2;
        n = n / 2;
        if(r == 1)
        {
            res = (res * b) % m;
        }
        b = (b * b) % m;
    }
    cout << "结果为" << res << endl;
    return 0;
}
