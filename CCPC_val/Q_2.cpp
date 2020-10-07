#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        printf("%.2f\n", pow(sqrt(2), num - 1));
    }
    return 0;
}
