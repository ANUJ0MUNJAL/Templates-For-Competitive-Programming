#include<bits/stdc++.h>

using namespace std;

class BIT {

    public:
    vector<int> bit;  // binary indexed tree

    BIT (vector<int> arr) {
        // The number of nodes in a binary indexed tree 
        // is 1 more than the elements in the array
        bit.assign (arr.size() + 1, 0);
        for (size_t i = 0; i < arr.size(); i++) {
            // Create a binary indexed tree array (bit) from the array elements
            // We fill the binary indexed from index 1
            Add (i+1, arr[i]);
        }
    }

    // Find the sum of elements from the beginning upto right.
    int Sum (int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index = index - (index & (-index));
        }
        return sum;
    }

    // Find the sum of array elements from left upto right.
    int Range_Sum (int left, int right) {
        return Sum (right + 1) - Sum (left);
    }

    // Update the binary index tree element(s) at index
    void Add (int index, int delta) {
        while (index < bit.size()) {
            bit[index] += delta;
            index = index + (index & (-index));
        }
    }

    void Print_BIT () {
        cout << "\nBinary Indexed Tree array ... " << endl;
        for (int i = 0; i < bit.size(); i++) {
            cout << "[" << i << "]:"<< bit[i] << " ";
        }
    }
};
