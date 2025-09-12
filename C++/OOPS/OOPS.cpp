// #include <iostream>
// #include<string>
// using namespace std ;
// class Animal  {
//     public:
//     void eat(){
//         cout<<" Eat \n" ;

//     }
//     void sleep(){
//         cout<<" Sleep \n";
//     }
// };
// class Man : public Animal {
//     public :
//     void gym(){
//         cout<<" Man do GYM \n";

//     }

// };
// class Woman : public Animal {
//     public :
//     void study(){
//         cout<<" Women do Study \n";

//     }

// };
// int main()
// {
//     Man M1 ;
//     Woman W1;
//     M1.eat();

//     M1.gym();
//     W1.sleep();
//     W1.study();

// }

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