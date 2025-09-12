
// #include <iostream>
// using namespace std ;
// int main (){
//     for (int i = 0 ; i<15 ; i++){
//         for (int j = 0 ; j<i+1 ; j++){
//             cout << " * " ;
//         }
//         cout << " " << endl ;
//     }
//     return 0 ;
// }

// #include <iostream>
// using namespace std;
// int main()
//{
// int arr[6] = {1, 2, 3, 4, 5, 6};
// for (int i = 0 ; i<6 ; i++){
//     cout << arr[i] << " " ;

// }

// return 0;

//     int arr[5];
//     int n = sizeof(arr) / sizeof(int);

//     cout << " Enter Your Array Here : " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0 ;
// }
#include <iostream>
using namespace std;
int stock(int *arr, int n)
{

    int bestBuy[n];
    bestBuy[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        bestBuy[i] = min(bestBuy[i - 1], arr[i - 1]);
    }

    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        int currProfit = arr[i] - bestBuy[i];
        maxProfit = max(currProfit, maxProfit);
    }
    cout << " Maximum Profit in One-Time Buy and Sell Stock is : " << maxProfit << endl;
}
int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(int);
    stock(arr, n);
    return 0;
}