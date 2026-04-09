#include <iostream>
#include <vector>
using namespace std;

vector<int> insert(vector<int>nums, int val){
    nums.push_back(val);
    int x = nums.size()-1;
    int parentIndex = (x-1)/2;
    while(parentIndex>=0 && nums[x]>nums[parentIndex]){
        swap(nums[x], nums[parentIndex]);
        x = parentIndex;
        parentIndex = (x-1)/2;
    }
    return nums;
    
}

int main(){
    vector<int>nums={15, 12, 10, 8, 5, 3};
    vector<int>res = insert(nums, 2);
    for(int i = 0 ; i<res.size();i++){
        cout<< res[i] << " -> ";
    }
    return 0;
}