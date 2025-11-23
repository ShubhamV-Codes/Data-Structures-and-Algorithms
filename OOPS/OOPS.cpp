

#include <iostream>
#include <string>
using namespace std;
int func(int arr[], int i, int key)
{
    if (i>=7)
    {
        return -1 ;
    }

    if (arr[i] = key)
    {
        return i;
    }
    return func(arr, i + 1, key);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int key = 5;
    cout << func(arr, 0, 5);
    return 0;
}