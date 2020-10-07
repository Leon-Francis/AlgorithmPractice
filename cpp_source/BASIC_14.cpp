#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int h = n / 3600;
    int m = (n - h * 3600) / 60;
    int s = n % 60;
    cout << h << ":" << m << ":" << s << endl;
    return 0;
}
