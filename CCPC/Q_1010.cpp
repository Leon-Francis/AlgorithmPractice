#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    double sum = 0;
    for (int i = 1; i <= 30; i++)
    {
        double num = 1;
        for (int j = 1; j <= i; j++)
        {
            num *= j;
        }
        sum += num;
    }
    printf("%.2e", sum);
    return 0;
}
