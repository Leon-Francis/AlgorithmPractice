#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int nums[10] = {3, -5, 2, -7, 3, -3, 0, 3, -8, 10};
    int b[10];
    b[9] = nums[9];
    int max = nums[9];
    int index = 9;
    int end[10];
    end[9] = 9;
    for (int i = 8; i >= 0; i--)
    {
        if (b[i + 1] > 0)
        {
            b[i] = nums[i] + b[i + 1];
            end[i] = end[i + 1];
        }
        else
        {
            b[i] = nums[i];
            end[i] = i;
        }
        if (max < b[i])
        {
            max = b[i];
            index = i;
        }
    }
    if (max > 0)
    {
        cout << max << endl;
        cout << "最优解为从第" << index + 1 << "个元素开始，从第" << end[index] + 1 << "个元素结束。" << endl;
    }
    else
    {
        cout << 0 << endl;
        cout << "最优解为不取任何元素。" << endl;
    }
    return 0;
}
