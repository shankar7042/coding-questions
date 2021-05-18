#include<iostream>
using namespace std;

struct Pair {
	int min;
	int max;
};

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

struct Pair max_min_arr(int arr[], int size) {
	struct Pair min_max;

	if(size == 1) {
		min_max.min = arr[0];
		min_max.max = arr[0];
	} else {
		if(arr[0] < arr[1]) {
			min_max.min = arr[0];
			min_max.max = arr[1];
		} 
		else {
			min_max.min = arr[1];
			min_max.max = arr[0];	
		}
		
		for(int i = 2; i < size; i++) {
			if(min_max.max < arr[i]) {
				min_max.max = arr[i];
			}
			else {
				min_max.min = arr[i];
			}
		}
 	}
	
	return min_max;
}

// Tournament Method
struct Pair max_min_arr_recursive(int arr[], int low, int high) {
	struct Pair min_max, min_max_left, min_max_right;
	int mid;

	if(low == high) {
		min_max.min = arr[low];
		min_max.max = arr[low];
		return min_max;
	} 
	if(high == low + 1) {
		if(arr[low] < arr[high]) {
			min_max.min = arr[low];
			min_max.max = arr[high];
		} else {
			min_max.min = arr[high];
			min_max.max = arr[low];
		}
		return min_max;
	} 
	
	// Split the arr into two halfs left and right
	// Calculate the min and max for both of halfs
	// Compare the min of both halfs and calculate the real min of total arr
	// Compare the max of both halfs and calculate the real max of total arr

	mid = (low + high) / 2;
	min_max_left = max_min_arr_recursive(arr, low, mid);
	min_max_right = max_min_arr_recursive(arr, mid + 1, high);

	if(min_max_left.min < min_max_right.min) {
		min_max.min = min_max_left.min;
	} 
	else {
		min_max.min = min_max_right.min;
	}

	if(min_max_left.max > min_max_right.max) {
		min_max.max = min_max_left.max;
	} 
	else {
		min_max.max = min_max_right.max;
	}

	return min_max;
}

int main() {
	int size;
	cin >> size;
	int arr[size];
	inputArr(arr, size);
	// struct Pair min_max_pair = max_min_arr(arr, size);
	struct Pair min_max_pair = max_min_arr_recursive(arr, 0, size -1);
	cout << "Minimum number in arr is: " << min_max_pair.min << endl;
	cout << "Maximum number in arr is: " << min_max_pair.max << endl;
	return 0;
}