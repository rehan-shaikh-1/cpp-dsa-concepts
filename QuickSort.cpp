/*
------------------------------------------------------------
Program Name : Quick Sort using Vector
Developed By : Rehan Shaikh
Date         : 10 / 11 / 2025
Description  : This program demonstrates Quick Sort 
               using C++ STL vectors. It sorts the array 
               in ascending order.
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(vector<int> &arr, int low, int high) {
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];  // Middle element as pivot
    int i = low, j = high;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

// Function to perform Quick Sort recursively
void QuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi, high);
    }
}

int main() {
    vector<int> arr = {1, 7, 3, 14, 5};

    cout << "\nBefore Quick Sort: ";
    for (int val : arr)
        cout << val << " ";

    QuickSort(arr, 0, arr.size() - 1);

    cout << "\nAfter Quick Sort:  ";
    for (int val : arr)
        cout << val << " ";

    cout << endl;
    return 0;
}
