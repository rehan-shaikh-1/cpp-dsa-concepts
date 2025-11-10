/*
------------------------------------------------------------
Program Name : Insertion Sort using Vector
Developed By : Rehan Shaikh
Date         : 08 / 11 / 2025
Description  : This program demonstrates Insertion Sort 
               using C++ STL vectors. It sorts the array 
               in ascending order.
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to perform Insertion Sort
void InsertionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    vector<int> is = {1, 7, 3, 14, 5};

    cout << "\nBefore Insertion Sort: ";
    for (int s : is)
        cout << s << " ";

    InsertionSort(is);

    cout << "\nAfter Insertion Sort:  ";
    for (int s : is)
        cout << s << " ";

    cout << endl;
    return 0;
}
