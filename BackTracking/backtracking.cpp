// #include <iostream>
// using namespace std;
// void printArr(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }  
// void changeArr(int arr[], int n, int i)
// {
//     if (i == n)
//     {
//         printArr(arr, n);
//         return;
//     }
//     arr[i] = i + 1;
//     changeArr(arr, n, i + 1);
//     arr[i] -= 3;
// }
// int main()
// {
//     int arr[5] = {0};
//     int n = 5;
//     changeArr(arr, n, 0);
//      printArr(arr, n);
//     return 0;
// }

#include <iostream>
using namespace std;
void printSubSets(string str, string subset)
{
    if (str.size() == 0)
    {
        cout << subset << "\n";
        return;
    }
    char ch = str[0];

    printSubSets(str.substr(1, str.size() - 1), subset + ch);

    printSubSets(str.substr(1, str.size() - 1), subset);
}
int main()
{
    string str = "abc";
    string subset = "";

    printSubSets(str, subset);
    return 0;
}
