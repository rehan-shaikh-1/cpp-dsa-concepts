/*
------------------------------------------------------------
Program Name : Selection Sort using Vector
Developed By : Rehan Shaikh
Date         : 08 / 11 / 2025
Description  : This program demonstrates Selection Sort 
               using C++ STL vectors. It sorts the array 
               in ascending order.
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to perform true Selection Sort
void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;  // Assume current index is smallest
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap only once per outer loop
        if (minIndex != i)
            swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> ss = {1, 7, 3, 14, 5};

    cout << "\nBefore Selection Sort: ";
    for (int s : ss)
        cout << s << " ";

    selectionSort(ss);

    cout << "\nAfter Selection Sort:  ";
    for (int s : ss)
        cout << s << " ";

    cout << endl;
    return 0;
}
