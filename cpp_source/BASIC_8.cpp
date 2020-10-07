#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    for (int i = 1000; i<10000; i++)
    {
        int nums[4];
        nums[3] = i % 10;
        nums[2] = (i / 10) % 10;
        nums[1] = (i / 100) % 10;
        nums[0] = (i / 1000) % 10;
        if(nums[3] == nums[0])
        {
            if(nums[2] == nums[1])
            {
                cout << i << endl;
            }
        }
    }
    return 0;
}
