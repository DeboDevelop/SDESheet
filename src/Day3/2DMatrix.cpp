/**

Search a 2D Matrix

Link: https://leetcode.com/problems/search-a-2d-matrix/

Link 2: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

*/

#include <bits/stdc++.h>
using namespace std;

// Optimal (for GFG) / Better (for LeetCode)
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = m - 1;
    while(i < n && j >= 0) {
        if(matrix[i][j] == target) {
            return true;
        }
        if(matrix[i][j] > target) {
            j--;
        } else {
            i++;
        }
    }
    return false;
}

// Optimal (for LeetCode)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size()) return false;

    int n = matrix.size(), m = matrix[0].size();

    int low = 0, high = (n * m) - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(matrix[mid / m][mid % m] == target) {
            return true;
        }
        if(matrix[mid / m][mid % m] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    bool result = searchMatrix(matrix, target);
    cout << boolalpha;
    cout << "Result: " << result << "\n";
    return 0;
}