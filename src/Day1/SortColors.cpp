/**

Sort an array of 0’s 1’s 2’s without using extra space or sorting algo

Link: https://leetcode.com/problems/sort-colors/

*/

#include <bits/stdc++.h>
using namespace std;

// Optimal - Dutch National Flag Algorithm
void DNFA(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() -1;

    while (mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else if(arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// Better - Counting Sort
void countingSort(vector<int>& arr) {

    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
 
    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
 
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = { 2, 0, 2, 1, 1, 0 };
    DNFA(arr);
    printArray(arr);
    return 0;
}