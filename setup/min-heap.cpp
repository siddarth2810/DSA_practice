#include<bits/stdc++.h>
using namespace std;


class MinHeap{
	public:
		vector<int> heap;
		
		void heapifyUp(int index){
			while(index > 0) {
				int parentIndex = (index -1) /2;
				if(heap[index] < heap[parentIndex]){
					swap(heap[index], heap[parentIndex]);
					index = parentIndex;
				}else {
					break;
				} 
				
			}
		}

		void heapifyDown(int index){
			int size = heap.size();

			while(true) {
				int left = 2*index +1;
				int right = 2*index +2;
				int smallest = index;

				if(left < size && heap[left] < heap[smallest])
					smallest = left;
				if(right < size && heap[right] < heap[smallest])
					smallest = right;

				if(smallest != index){
					swap(heap[index], heap[smallest]);
					index = smallest;
				}else {
					break;
				}
			}
		}


		void insert(int val){
			heap.push_back(val);
			heapifyUp(heap.size() -1);
		}

		int getMin() const {
			if(heap.empty()){
				out_of_range("heap is empty");
			}
			return heap[0];
		}

		int extractMin() {
			if(heap.empty()){
				out_of_range("heap is empty");
			}
			int minVal = heap[0];
			heap[0] = heap.back();
			heap.pop_back();
			heapifyDown(0);
			return minVal;
		}

		   bool isEmpty() const {
        return heap.empty();
    }

    // Print the heap (for debugging)
    void printHeap() const {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

};


int main() {
    MinHeap mh;

    mh.insert(10);
    mh.insert(4);
    mh.insert(15);
    mh.insert(20);
    mh.insert(0);

    std::cout << "Heap elements: ";
    mh.printHeap();  // should print the heapified array

    std::cout << "Minimum: " << mh.getMin() << std::endl;

    std::cout << "Extracted min: " << mh.extractMin() << std::endl;
    std::cout << "Heap after extraction: ";
    mh.printHeap();

    return 0;
}




