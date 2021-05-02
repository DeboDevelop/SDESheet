/**

Majority Element

Link: https://leetcode.com/problems/majority-element/

*/

#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;

    for(int num : nums) {
        if(count == 0) {
            candidate = num;
        }
        if(num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << "Result: " << majorityElement(nums) << "\n";
    return 0;
}