/**

Rotate Image

Link: https://leetcode.com/problems/rotate-image/

*/

#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < i; j++) {
            swap( matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i < size; i++) {
        reverse( matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    printMatrix(matrix);
    rotate(matrix);
    printMatrix(matrix);
    return 0;
}