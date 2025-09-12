#include <iostream>
using namespace std;

int majorElement(int *nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                num++;
            }
        }
        if (num > (n / 2))
        {
            return nums[i];
        }
    }
    return -1;
}

int main()
{
    int nums[] = {2,2,1,2,1,2,2,2,1,2,1,2,2};
    int n = sizeof(nums) / sizeof(int);
     cout << majorElement(nums, n) << "  is in the Majority " <<"  ";
     cout<<endl ; 
    return 0;
}