#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % a != 0 && i % b != 0 && i % c != 0)
        {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
