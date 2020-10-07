#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b;
    cout << "请输入a,b: ";
    cin >> a >> b;
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int form[3][4] = {0};
    form[0][3] = a;
    form[1][0] = 1;
    form[1][1] = 0;
    form[1][3] = b;
    form[2][0] = 0;
    form[2][1] = 1;
    form[2][2] = 1;
    form[2][3] = a % b;
    while (form[2][3] != 0)
    {
        for (int i = 0; i < 4; i++)
        {
            form[0][i] = form[1][i];
            form[1][i] = form[2][i];
        }
        form[2][0] = -1 * form[1][2] * form[1][0] + form[0][0];
        form[2][1] = -1 * form[1][2] * form[1][1] + form[0][1];
        form[2][2] = form[0][3] / form[1][3];
        form[2][3] = -1 * form[2][2] * form[1][3] + form[0][3];
    }
    cout << form[2][0] << " * " << a << " + " << form[2][1] << " * " << b << " = " << form[1][3] << endl;
    return 0;
}
