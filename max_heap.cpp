#include<bits/stdc++.h>
using namespace std;
/*
    Max HEAP
    push -> O(logn)
    pop -> O(1) if top is popped , O(logn) -> is certain element needs to be popped
    build -> O(n * logn)
*/

class PriorityQueue {
private:
    vector<int> v;
        
    int parent(int i) { return i == 0 ? 0 : (i-1)/2; }
    int left(int i) { return 2*i + 1; }
    int right(int i) { return 2*i + 2; }

    //carrys down the min node from root after popping
    void heapifyDown(int i) {
        int largest = i;
        int L = left(i), R = right(i);

        if(L < size() && v[largest] < v[L])
            largest = L;
        if(R < size() && v[largest] < v[R])
            largest = R;

        if(largest != i) {
            swap(v[i], v[largest]);

            heapifyDown(largest);
        }
    }

    //carrys the last inserted node up if it greater than its parent
    void heapifyUp(int i) {
        if(i && v[parent(i)] < v[i]) {
            swap(v[parent(i)], v[i]);
            heapifyUp(parent(i));
        }
    }
public:
    unsigned int size() { return v.size(); }
    bool empty() { return v.empty(); }

    void push(int x) {
        v.push_back(x);
        heapifyUp(size()-1);
    }
    void pop() {
        try {
            if(v.size() == 0) {
                throw out_of_range("Heap is empty !");
            }

            v[0] = v.back();
            v.pop_back();

            //settles the root node where it is the greatest among its children
            heapifyDown(0);
        }
        catch(const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
    int top() {
        try {
            if(v.size() == 0) {
                throw out_of_range("Heap is empty !");
            }
            return v[0];
        }
        catch(const out_of_range &oor) {
            cout << endl << oor.what();
        }
        return 0;
    }
};

int main() {
    PriorityQueue pq;
 
    // Note: The element's value decides priority
 
    pq.push(3);
    pq.push(2);
    pq.push(15);
 
    cout << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.push(5);
    pq.push(4);
    pq.push(45);
 
    cout << endl << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << endl << boolalpha << pq.empty();
 
    pq.top();    // top operation on an empty heap
    pq.pop();  
    return 0;
}