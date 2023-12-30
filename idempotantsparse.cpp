// using sparse table
#include <bits/stdc++.h>
using namespace std;
#define MAX 500
 

int table[MAX][MAX];
 
void buildSparseTable(int arr[], int n)
{

    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];
 
    for (int j = 1; j <= log2(n); j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = __gcd(table[i][j - 1],
                    table[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R)
{

    int j = (int)log2(R - L + 1);
 
    return __gcd(table[L][j], table[R - (1 << j) + 1][j]);
}