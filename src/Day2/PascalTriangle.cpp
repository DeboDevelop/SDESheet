/**

Pascal's Triangle

Link: https://leetcode.com/problems/pascals-triangle/

*/

#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

// Solution 1 - Print the Whole matrix
void generate(int numRows) {
    vector<vector<int>> r(numRows);

    for(int i = 0; i < numRows; i++) {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;

        for(int j = 1; j < i; j++) {
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
    }
    printMatrix(r);
}

int main()
{
    generate(5);
    return 0;
}