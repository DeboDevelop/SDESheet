/**

Best Time to Buy and Sell Stock

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

*/

#include <bits/stdc++.h>
using namespace std;

// Optimal Soluton 
int maxProfit(vector<int>& prices) {
    int profit = 0, minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        profit = max(profit, prices[i] - minPrice);
    }
    return profit;
}

// Brute Force Solution
int bruteForce(vector<int>& prices) {
    int profit = 0;
    for(int i = 0; i < prices.size(); i++) {
        for(int j = i + 1; j < prices.size(); j++) {
            profit = max((prices[j] - prices[i]), profit);
        }
    }
    return profit;
}

int main()
{
    vector<int> prices = { 7,1,5,3,6,4 };
    cout << maxProfit(prices) << "\n";
    return 0;
}