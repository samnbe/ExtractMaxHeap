//Worked with Trevor Gross
#include <iostream>

void percolateDown(int arr[], int size, int parent) {
    int left = (2*parent) + 1;
    int right = (2*parent) + 2;
    int maxIndex = parent;

    if (right < size && arr[right] > arr[maxIndex])
	maxIndex = right;
    if (left < size && arr[left] > arr[maxIndex])
	maxIndex = left;
    if (maxIndex != parent) {
	std::swap(arr[maxIndex], arr[parent]);
	percolateDown(arr, size, maxIndex);
    }
}

int* extractMax(int arr[], int size) {
    if (size == 0){
	return nullptr;
    }
    arr[0] = arr[size - 1];
    size--;
    percolateDown(arr, size, 0);
    
    return arr;
}

