#include <iostream>
using namespace std;

void MoveTowers(int n, int tower1[52], int tower2[52], int tower3[52])
{
    if (n == 1)
    {
        int temp = tower1[--tower1[1]];
        tower3[tower3[1]++] = temp;
        cout << "move disk " << temp << " from tower " << tower1[0] << " to tower " << tower3[0] << endl;
        ;
        return;
    }
    MoveTowers(n - 1, tower1, tower3, tower2);
    int temp = tower1[--tower1[1]];
    tower3[tower3[1]++] = temp;
    cout << "move disk " << temp << " from tower " << tower1[0] << " to tower " << tower3[0] << endl;
    MoveTowers(n - 1, tower2, tower1, tower3);
    return;
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "请输入塔的高度：";
    cin >> n;
    int tower1[52];
    int tower2[52] = {2, 2};
    int tower3[52] = {3, 2};
    tower1[0] = 1;
    tower1[1] = n + 2;
    for (int i = n + 1; i > 1; i--)
    {
        tower1[i] = n - i + 2;
    }
    MoveTowers(n, tower1, tower2, tower3);
    return 0;
}
