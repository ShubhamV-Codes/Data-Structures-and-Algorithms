#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Heap
{
    vector<int> vec;

     void heapify(int i)
    {
        int n = vec.size(); 
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maxI = i;

        if (left < n && vec[left] > vec[maxI])
            maxI = left;
        if (right < n && vec[right] > vec[maxI])
            maxI = right;

        if (maxI != i)
        {
            swap(vec[i], vec[maxI]);
            heapify(maxI);
        }
    } 

public:
    // PUSH FUNCTION IN HEAP  O(logn){ to fixing heap after inserting}

   
    void push(int val)
    {

        // 1.Push Value in Vector vec
        vec.push_back(val);

        // 2.Fix The Heap
        int x = vec.size() - 1;
        int parentIdx = (x - 1) / 2;

        while (parentIdx >= 0 && vec[x] > vec[parentIdx])
        {
            swap(vec[x], vec[parentIdx]);
            x = parentIdx;
            parentIdx = (x - 1) / 2;
        };
    }
    //   POP FUNCTION IN HEAP O(logn)
    int pop()
    {
        int n = vec.size();
        if (n <= 0)
        {
            throw runtime_error("Heap underflow");
        }

        int root = vec[0];   // max element
        vec[0] = vec[n - 1]; // replace root with last
        vec.pop_back();       // shrink vector
        if (!vec.empty()) {
            heapify(0);       // restore heap property
        }
        return root;
    }

    //    TOP FUNCTION IN HEAP O(1)
    int top()
    {
        return vec[0];
    }

    //    EMPTY FUNCTION IN HEAP
    bool empty()
    {
        return vec.size() == 0;
    }
};

int main()
{
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);
    for(int i=0;i<3;i++){
 cout << "Popped max: " << heap.pop() << endl;
    }
    return 0;
}