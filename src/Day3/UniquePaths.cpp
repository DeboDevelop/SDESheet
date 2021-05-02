/**

Unique Paths

Link: https://leetcode.com/problems/unique-paths/

*/

#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
int uniquePaths(int m, int n) {
    int N = n + m -2;
    int r = m -1;
    double res = 1;

    for(int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;

    return (int)res;
}

int UP(int m, int n, vector<vector<int>> &memo){
    //move out of boundary, it's invalid, should not be counted as a path
    if(m < 0 || n <0) return 0;
    //Robot hits the boundary, we can guarantee to have one way to reach the destination
    if(m==0 || n==0) return 1;
    
    if(memo[m][n] > 0) return memo[m][n];
            
    //We calculate the sum of how many panths from two paths
    return memo[m][n] = UP(m-1, n, memo) + UP(m, n-1, memo);
}

// Better Solution
int uniquePaths1(int m, int n) {
    if(m <=0 || n <= 0) return 0;
    vector<vector<int>> memo(m, vector<int>(n, 0));
    return UP(m-1, n-1, memo);
}

// Brute Force Solution
int countPaths1(int i, int j, int n, int m) {
    if(i == (n - 1) && j == (m - 1)) return 1;
    if(i >= n || j >= m) return 0;
    else return countPaths1(i+1, j, n, m) + countPaths1(i, j+1, n, m);
}

int main() {
    cout << uniquePaths(3, 3) << "\n";
    return 0;
}