#include<bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    const static int MAX = 20; // Maximum log2 value

    vector<vector<int>> table; // 2D array to store ancestor information

    TreeAncestor(int n, vector<int>& parent) {
        table.resize(MAX, vector<int>(n + 1, -1)); // Initialize the 2D array with -1

        // Fill the first column of the table with direct parents
        for (int j = 0; j < n; ++j) {
            table[0][j] = parent[j];
        }

        // Fill the rest of the table using binary lifting
        for (int i = 1; i < MAX; ++i) {
            for (int j = 0; j < n; ++j) {
                if (table[i - 1][j] != -1) {
                    table[i][j] = table[i - 1][table[i - 1][j]];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int len = (int)log2(k); // Calculate the maximum exponent of 2 in k

        for (int i = 0; i <= len; ++i) {
            if (k & (1 << i)) { // If the i-th bit of k is set
                node = table[i][node];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};