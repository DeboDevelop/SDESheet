/**

Kadane’s Algorithm

Link: https://leetcode.com/problems/maximum-subarray/

*/

#include <bits/stdc++.h>
using namespace std;

void kadane_algorithm(vector<int>& arr) {

    int sum = 0, maxi = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }

    cout << "Sum : " << maxi << "\n";
}

// Better - using 2 loops
void loop_method(vector<int>& arr) {

    int sum = 0, maxi = arr[0];

    for(int i = 0; i < arr.size(); i++ ) {
        sum = 0;

        for(int j = i; j < arr.size(); j++ ) {
            sum+=arr[j];

            if(sum > maxi) {
                maxi = sum;
            }
        }
    }
    
    cout << "Sum : " << maxi << "\n";
}

int main() {

    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    kadane_algorithm(arr);

    return 0;
}