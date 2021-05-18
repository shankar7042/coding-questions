#include<iostream>
using namespace std;

// Two type sof Heap
// 1. Max Heap in which all the child is less than or equal to the parent node 
// OR
// In Max Heap the parent node is always geater than the child nodes
// 2. Min Heap
// Reverse of the Max heap is Min Heap meaning 
// all the parent node have less value than their child node

// Here we are using a array to represent the Heap data Structure
//		  20
//	   /      \
//	  12      18
//	 /  \    /  \
//	10   8  15  13

// It is represented as array as
// [20, 12, 18, 10, 8, 15, 13]
// We can find the child node from parent node index value as
// let parent index value i = 2
// then children index is 1. 2*i + 1 = 2*2 + 1 = 5
//                        2. 2*i + 1 = 2*2 + 2 = 6

// In this arr we can verify that index 2 has value = 18 and their children is 
// at index 5 (15) and 6 (13)

// We can also find the parent index value from the child index value as
// let if child node index value is 5 or 6 the the parent node should be at (i - 1) / 2 floor value

void inputArr(int arr[], int size) {
	int num;
	for(int i = 0; i < size; i++) {
		cin >> num;
		arr[i] = num;
	}
}

void printArr(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

// Max Heap
void maxHeapify(int arr[], int size) {
	int parentIndex, y;
	for(int i = 1; i < size; i++) {
		y = i;
		parentIndex = (y - 1) / 2;
		while(parentIndex >= 0 && arr[parentIndex] < arr[y]) {
			swap(arr[parentIndex], arr[y]);
			y = parentIndex;
			parentIndex = (y - 1) / 2;
		}
	}	
}

// Min Heap
void minHeapify(int arr[], int size) {
	int parentIndex, y;
	for(int i = 1; i < size; i++) {
		y = i;
		parentIndex = (y - 1) / 2;
		while(parentIndex >= 0 && arr[parentIndex] > arr[y]) {
			swap(arr[parentIndex], arr[y]);
			y = parentIndex;
			parentIndex = (y - 1) / 2;
		}
	}	
}


int main() {
	int size;
	cin >> size;
	int arr[size];
	inputArr(arr, size);
	printArr(arr, size);
	maxHeapify(arr, size);
	printArr(arr, size);
	minHeapify(arr, size);
	printArr(arr, size);
	return 0;
}