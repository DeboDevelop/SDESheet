/**

Next Permutation

Link: https://leetcode.com/problems/next-permutation/

*/

#include <bits/stdc++.h>
using namespace std;

//Optimal Solution
void nextPermutation(vector<int>& nums) {
    int n = nums.size(), k, l;
    for( k = n - 2; k >= 0; k--) {
        if(nums[k] < nums[k + 1]) {
            break;
        }
    }
    if(k < 0) {
        reverse(nums.begin(), nums.end());
    } else {
        for(l = n - 1; l > k; l--) {
            if(nums[l] > nums[k]) {
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        cout<<nums[i];
    }
    cout<<"\n";
}

// Brute Force Solution
void permute(vector<int>& nums, int l, int r, vector<vector<int>>& result)
{
    // Base case
    if (l == r) {
        result.push_back(nums);
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     cout<<nums[i];
        // }
        // cout<<"\n";
    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(nums[l], nums[i]);
 
            // Recursion called
            permute(nums, l+1, r, result);
 
            //backtrack
            swap(nums[l], nums[i]);
        }
    }
}

// Have to rewrite this search function
void search(vector<vector<int>>& result, vector<int>& nums) {
    // for(int i = 0; i<result.size(); i++) {
    //     if(result[i][0] == nums[0] && result[i][1] == nums[1] && result[i][2] == nums[2] && i+1 != result.size()) {
    //         for (int j = 0; j < result[i+1].size(); ++j)
    //         {
    //             cout<<result[i][j];
    //         }
    //         cout<<"\n";
    //     }
    // }
}

int main() {
    vector<int> nums = { 1, 2, 3 };
    nextPermutation(nums);
    return 0;
}