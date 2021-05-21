#include <stdio.h>
using namespace std;

long long labs(long long x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}

int main()
{
    long long T;
    scanf("%lld", &T);
    long long A, B;
    for (long long i = 0; i < T; i++)
    {
        scanf("%lld%lld", &A, &B);
        long long C = A - B;
        if (A < 0 || B < 0)
        {
            printf("NO\n");
        }
        else if (labs(C) > 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}