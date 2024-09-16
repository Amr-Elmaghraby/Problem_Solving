#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// @brief Works only with an integer array
// Assuming that the max value inside array isn't big 'For complexity'
/// @param arr 
void countingSort(vector<int>& arr) {
    // Find the maximum value in the array
    int maxValue = *max_element(arr.begin(), arr.end());
    
    // Create a count array to store the count of each unique value
    vector<int> count(maxValue + 1, 0);

    // Store the count of each element
    for (int num : arr) {
        count[num]++;
    }

    // Modify the original array by putting elements in sorted order
    int index = 0;
    for (int i = 0; i <= maxValue; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 1000, 3, 3, 1};
    countingSort(arr);

    // Output the sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
