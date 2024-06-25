/* 
Min heap

Find the missing element

Time Complexity: 
get, parentNode, leftNode, rightNode, isLeafNode, swap: O(1)
minHeapify, remove, print: O(n)
insert: Average case O(1), Worst case: O(n)

Space Complexity: O(1)

*/

#include <iostream>
class MinHeap{

private:
    int count;
    int size;
    int minHeap[50]; 

    int get(){
        return this->minHeap[1];
    }

    int parentNode(int pos) {
        return pos/2;
    }
    
    int leftNode(int pos){
        return (2 * pos);
    }

    int rightNode(int pos){
        return (2 * pos) + 1;
    }

    int isLeafNode(int pos){
        if (pos > (size /2) && pos < size){
            return true;
        }
        return false;
    }

    void swap(int first, int second){
        int tmp;
        tmp =  minHeap[first];
        minHeap[first] = minHeap[second];
        minHeap[second] = tmp;
    }

    void minHeapify(int pos){
        if(!isLeafNode(pos)){
            int swapPos = pos;
            if(rightNode(pos) < size){
                swapPos = minHeap[leftNode(pos)] < minHeap[rightNode(pos)] ? leftNode(pos) : rightNode(pos);
            }
            else{
                swapPos = leftNode(pos);
            }
            if(minHeap[pos] > minHeap[leftNode(pos)] || minHeap[pos] > rightNode(pos)){
                swap(pos, swapPos);
                minHeapify(swapPos);
            }
        }
    }

public:

    MinHeap() : count(0), size(10) {
        minHeap[0] = -1;
    }

    void insert(int element){
        if (count > size) return;

        minHeap[++count] = element;
        int current = count;
        while(minHeap[current] < minHeap[parentNode(current)]){
            swap(current, parentNode(current));
            current = parentNode(current);
        }
    }

    int remove(){
        int top_element = minHeap[1];
        minHeap[1] = minHeap[--count];
        minHeapify(1);
        return top_element;
    }

    void print(){
        for (int i = 1; i <= count/2; i++){
            std::cout << "Parent: " << minHeap[i] << " Left Child: " << minHeap[leftNode(i)] << " Right Child: " << minHeap[rightNode(i)] << std::endl;
        }
    }

};

int main(){
    std::cout << "The Min Heap is " << std::endl;

    MinHeap minimumHeap = MinHeap();

    minimumHeap.insert(5);
    minimumHeap.insert(3);
    minimumHeap.insert(17);
    minimumHeap.insert(10);
    minimumHeap.insert(84);
    minimumHeap.insert(19);
    minimumHeap.insert(6);
    minimumHeap.insert(22);
    minimumHeap.insert(9);

    minimumHeap.print();

    std::cout << "The Min value in the heap is: " << minimumHeap.remove() << std::endl;

    std::cout << "The new Min Heap is" << std::endl;
    minimumHeap.insert(33);
    minimumHeap.print();
    return 0;
}
