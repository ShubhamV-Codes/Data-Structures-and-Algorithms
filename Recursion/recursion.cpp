
        //    FRIENDS-PAIRING PROBLEM

// #include<iostream>
// #include<string>
// using namespace std ;
// int friendsPairing(int n){
//     if(n==1 || n==2){
//         return n ;
//     }
//     return friendsPairing(n-1) +  (n-1) *friendsPairing(n-2) ;

// }
// int main(){
//     cout<<  friendsPairing(4) << endl ; 
//     return 0;
// }

//           TILING-PROBLEM  for 4*n


// #include <iostream>
// #include <string>
// using namespace std ;
// int tilingPro(int n){
//     if(n==0 || n==1 || n==2|| n==3){
//         return n ;

//     }
//     return tilingPro(n-1) + tilingPro(n-2);

// }
// int main(){
//     cout << tilingPro(3);
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std ;
// int firstOccurance (vector<int>arr , int target , int i){
//     if( arr[i] == target ){
//         return i ;

//     }
//     if(i==arr.size()){
//         return -1 ;

//     }
//     return firstOccurance(arr , target , i+1);
// }
// int main(){
//     vector<int>arr ={ 1,2,3,3,3,4};
//    cout<< firstOccurance(arr , 7, 0);
//     return 0;0


// }

#include <iostream>
#include <string>
#include <vector>
using namespace std ;
int lastOccur(vector<int>arr , int target , int i){
    if(i==arr.size()){
        return -1;

    }
    int idxFound = lastOccur(arr , target , i+1);

    if(idxFound==-1 && arr[i]==target){
        return i;
    }
    return idxFound ;
}
int main(){
    vector<int>arr = {1,2,3,3,3,4};
   cout << lastOccur(arr , 3 ,0) << endl;
    return 0; 
}
