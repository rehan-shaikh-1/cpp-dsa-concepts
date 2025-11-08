/*
------------------------------------------------------------
Program Name : Bubble Sort using Vector
Developed By : Rehan Shaikh
Date         : 08 / 11 / 2025
Description  : This program demonstrates Bubble Sort using 
               C++ STL vectors. It sorts the array in 
               ascending order.
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to perform Bubble Sort
void BubbleSort(vector<int> &arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no elements were swapped, array is already sorted
        if (!swapped)
            break;
    }
}

int main() {
    vector<int> bs = {1, 7, 3, 14, 5};

    cout << "\nBefore Bubble Sort: ";
    for (int s : bs)
        cout << s << " ";

    BubbleSort(bs);

    cout << "\nAfter Bubble Sort:  ";
    for (int s : bs)
        cout << s << " ";

    cout << endl;
    return 0;
}
