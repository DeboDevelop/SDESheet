/**

Find the duplicate in an array of N+1 integers

Link: https://leetcode.com/problems/find-the-duplicate-number/

*/

#include <bits/stdc++.h>
using namespace std;

// Optimal - Floyd's Tortoise and Hare method
int floyd_method(vector<int>& arr) {
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    fast = arr[0];

    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main() {

    vector<int> arr = { 1, 3, 4, 2, 2 };
    int duplicate = floyd_method(arr);

    cout << "The Duplicate No. is : " << duplicate << "\n";
    return 0;
}