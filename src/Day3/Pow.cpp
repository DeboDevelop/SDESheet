/**

Pow(x, n)

Link: https://leetcode.com/problems/powx-n/

*/

#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
double myPow(double x, int n) {
    double ans = 1.0;
    long pow = n;
    if(n < 0) pow = -1 * pow;
    while(pow > 0) {
        if(pow % 2 == 1) {
            ans = ans * x;
            pow--;
        } else {
            x *= x;
            pow /= 2;
        }
    }
    if(n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
}

// Brute Force Solution
double myPow1(double x, int n) {
    if(n == 0) return 1.0;
    double ans = 1.0;
    if(n > 0) {
        for(int i = 0; i < n; i++) {
            ans *= x;
        }
        return ans;
    } else {
        long pow = -n;
        for(int i = 0; i < pow; i++) {
            ans *= x;
        }
        return (1/ans);
    } 
}

int main()
{
    double x = 2.0; int n = 10;
    double result = myPow(x, n);
    cout << "Result: " << result << "\n";
    return 0;
}