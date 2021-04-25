/**

Find the repeating and the missing

Link: https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

*/

#include <bits/stdc++.h>
using namespace std;

//Optimal - Xor method
void xor_method(vector<int>& arr) {
    int xor_result = arr[0], missing = 0, repeating = 0, flag =0;
    for (int i = 1; i < arr.size(); i++)
    {
        xor_result = xor_result ^ arr[i];
    }
    for (int i = 1; i <= arr.size(); i++)
    {
        xor_result = xor_result ^ i;
    }
    int set_bit = xor_result & -xor_result;
    for (auto it: arr)
    {
        if(it & set_bit) {
            missing = missing ^ it;
        } else {
            repeating = repeating ^ it;
        }
    }
    for (int i = 1; i <= arr.size(); i++)
    {
        if(i & set_bit) {
            missing = missing ^ i;
        } else {
            repeating = repeating ^ i;
        }
    }
    for (auto it: arr)
    {
        if(repeating == it) {
            flag = 1;
        }
    }
    if(flag == 0) {
        swap(missing, repeating);
    }
    cout << "Missing :" << missing << "\n" << "Repeating: " << repeating << "\n";
}

// Better - Using 2 equations of square
void square(vector<int>& arr) {
    int n = arr.size();
    int sum = (n * (n+1))/2;
    long square_sum = (n*(n+1)*(2*n+1))/6;
    for (auto it : arr)
    {
        sum -= it;
        square_sum -= (it * it);
    }
    int missing = (sum + (square_sum/sum))/2;
    int repeating = missing - sum;
    cout << "Missing :" << missing << "\n" << "Repeating: " << repeating << "\n";
}

int main() {
    vector<int> arr = { 7, 3, 4, 5, 5, 6, 2 };
    // square(arr);
    xor_method(arr);
    return 0;
}