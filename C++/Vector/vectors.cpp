#include <iostream>
#include <vector>
using namespace std;

int main(){
     int row, col;
     cout << ("Enter Row Number : ") << endl ;
     cin>> row  ;
     cout<< ("Enter Column Number :") << endl ;
     cin>> col ;
     int**matrix = new int*[row] ;
     for(int i = 0 ; i<row ; i++){
        matrix[i] = new int[col];
     }
     int x=1;
     for(int i = 0 ; i<row ; i++){
        for(int j = 0 ; j<col ;j++){
            matrix[i][j] = x++ ;
            cout<<matrix[i][j] << " " ;

        }
        cout << endl ;
     }
     cout<<matrix[2][2] << endl ;
     cout<<*(*(matrix+2)+2) <<endl ;
     return 0 ;
}

// int main()
// {
//     vector<int> vec1 = {1, 2, 3, 4, 5};
//     vector<int> vec2 = {6, 7, 8, 9, 10};
//     for (int i = 0; i < 5; i++)
//     {

//         int ptr = vec1[i] + vec2[i];
//         cout << ptr << endl;
//     }
// }

// vector<int>funcLeet (vector<int>nums){
//     vector<int>answer ;
//     for(int i=0 ; i<nums.size() ; i++){
//         if(nums[i] == nums[i+1]){
//             return{i ,i+1};
//             answer.push_back(i);
//             answer.push_back(i+1);
//             return answer;
            
//         }

//     }

// }
// int main()
// {
//     vector<int>nums={1,2,2,4};
//     vector<int>answer = funcLeet(nums);

    
// }