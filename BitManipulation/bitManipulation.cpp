// #include<iostream>
// using namespace std ;
// int bit ( int n ,int i){
//     int bitMask =(~0)<<i ;
//      int num = n&bitMask  ;
//     cout << num ;
// }
// int main(){
//     int n =19999 ;
//     int i = 2 ;
//      bit(n , i);
//     return 0;

// }

// #include<iostream>
// using namespace std ;
// bool isPowerOf2(int num){
//     if(!(num&(num-1))){
//         return true ;
//     }else {
//         return false ;
//     }
// }
// int main(){
//    cout<< isPowerOf2(3);
//     return 0;
// }

// #include <iostream>
// using namespace std ;
// int clearBit(int n ,int i ,int j )
// {
//     while(i<=j){
//         int bitMask= n<<i;
//         n= bitMask&0;
//         i++;
//         n>>i;
//         return n;


//     }

// }
// int main(){
//     cout<<  clearBit(15,1,3);
//     return 0 ;
// }


#include <iostream>
#include <vector>
using namespace std ;
int singleNumber(vector<int>nums){
    int ans = 0;
    for(int i =0 ;i<nums.size() ; i++){
        ans ^=nums[i];
        
    }
    return ans ;

}
int main(){
    vector<int>nums = {2,2,4,4,1};
     cout<< singleNumber(nums);
    return 0;
}