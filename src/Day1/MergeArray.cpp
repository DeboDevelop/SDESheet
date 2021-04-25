/**

Merge two sorted Arrays without extra space

Link: https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/

*/

#include <bits/stdc++.h>
using namespace std;

int next_gap(int gap) {
    if (gap <= 1) 
        return 0;
    return ceil(gap / 2);
}

// Optimal - Shell Sort kind of algorithm, or the Gap method
void shell_sorting(int a[], int b[], int n, int m) {

    int i, j, gap;
    for (gap = next_gap(n + m); gap > 0; gap = next_gap(gap)) {

        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++) {
            if (a[i] > a[i + gap])
                swap(a[i], a[i + gap]);
        }
 
        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++) {

            if (a[i] > b[j])
                swap(a[i], b[j]);
        }
 
        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++) {
                if (b[j] > b[j + gap])
                    swap(b[j], b[j + gap]);
            }
        }
    }
}

// Better - Insertion Sort kind of algorithm
void insertion_sorting(int a[], int b[], int n, int m) {

    for (int i = 0; i < n; i++) {

        if(a[i] > b[0]) {

            swap(a[i], b[0]);
            int first_elem = b[0];
            int k;

            for (k = 1; k < m && b[k] < first_elem; k++) {
                b[k - 1] = b[k];
            }

            b[k -1] = first_elem; 
        }
    }
}

void print(int a[], int b[], int n, int m) {

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
 
    for(int i = 0; i < m; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";

}

int main() {

    int a[] = { 3, 5, 6, 8, 12 };
    int b[] = { 1, 4, 9, 13 };

    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);

    shell_sorting(a, b, n, m);

    print(a, b, n, m);

    return 0;
}