#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<float>& arr, int low, int high) {
    float pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; ++j) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            ++i; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap the elements
        }
    }
    // Swap the pivot element with the element at (i + 1)
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the pivot index
}

// Function to perform Quick Sort
void quickSort(vector<float>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<float> arr = {1,2,2,5,1,8,7,10};

    quickSort(arr, 0, arr.size() - 1);

    // Output the sorted array
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
