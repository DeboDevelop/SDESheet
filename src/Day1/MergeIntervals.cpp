/**

Merge Overlapping Subintervals

Link: https://leetcode.com/problems/merge-intervals/

*/

#include <bits/stdc++.h>
using namespace std;

void print_arr(vector <pair<int, int>>& arr) {
    for(auto it: arr) {
        cout<< it.first << " , "<< it.second << "\n";
    }
}

void sort_method(vector <pair<int, int>>& arr) {

    int start = 0, end = 0;
    sort(arr.begin(), arr.end());

    start = arr[0].first;
    end = arr[0].second;

    vector<pair<int, int>> result;

    for(auto it : arr) {

        if(it.first <= end) {

            end = max(it.second, end);
        } else {
            
            result.push_back(make_pair(start, end));
            start = it.first;
            end = it.second;
        }
    }

    result.push_back(make_pair(start, end));
    print_arr(result);
}

// Better Solution - with 2 loops
void loop_method(vector <pair<int, int>>& arr) {
    pair <int, int> temp;
    vector <pair<int, int>> result;

    for(int i = 0; i < arr.size(); i++) {
        temp = arr[i];

        for(int j = i + 1; j< arr.size(); j++) {

            if(temp.second > arr[j].first) {

                temp.second = max(temp.second, arr[j].second);
                arr[j].first = arr[j].second = INT_MIN;
            }
        }
        if(temp.first != INT_MIN || temp.second != INT_MIN)
            result.push_back(temp);
    }

    print_arr(result);
}

int main() {

    vector<pair<int, int>> arr = { { 1, 3}, { 2, 6}, { 8, 10}, { 15, 18} };
    sort_method(arr);

    return 0;
}