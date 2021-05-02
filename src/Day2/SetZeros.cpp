/**

Set Matrix Zeroes

Link: https://leetcode.com/problems/set-matrix-zeroes/

*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
void bruteForce(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j< cols; j++) {
            if(matrix[i][j] == 0) {
                for(int k=i+1;k < rows; k++) {
                    matrix[k][j] = -1;
                }
                for(int k=i-1;k >= 0; k--) {
                    matrix[k][j] = -1;
                }
                for(int k=j+1;k < cols; k++) {
                    matrix[i][k] = -1;
                }
                for(int k=j-1;k >= 0; k--) {
                    matrix[i][k] = -1;
                }
            }
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j< cols; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}

//Better Solution - 2 dummy array
void dummyArray(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> row(rows, 1); vector<int> col(cols, 1);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j< cols; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 0;
        col[j] = 0;
            }
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j< cols; j++) {
            if(row[i] == 0 || col[j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
}

//Optimal - Take 2 dummy array inside the matrix.
void setZeroes(vector<vector<int>>& matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for(int i = 0; i < rows; i++) {
        if(matrix[i][0] == 0) col0 = 0;
        for(int j = 1; j< cols; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for(int i = rows - 1; i >= 0; i--) {
        for(int j = cols - 1; j >= 1; j--) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if(col0 == 0) matrix[i][0] = 0;

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
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    printMatrix(matrix);
    setZeroes(matrix);
    printMatrix(matrix);
    return 0;
}