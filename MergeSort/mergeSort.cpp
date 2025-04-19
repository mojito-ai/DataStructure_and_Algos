#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int a[N];

/**
 * @brief Merges two sorted halves of the array `a` into a single sorted segment.
 * 
 * This function merges the elements in the range [l, mid] and [mid+1, r] of array `a`
 * using two temporary arrays `L` and `R` and a sentinel value (INT_MAX) to simplify logic.
 * 
 * @param l   Left index of the segment to be merged.
 * @param r   Right index of the segment to be merged.
 * @param mid Midpoint index dividing the two halves.
 */
void merge(int l, int r, int mid) {
    int l_sz = mid - l + 1;
    int L[l_sz + 1];  // +1 for sentinel
    int r_sz = r - (mid + 1) + 1;
    int R[r_sz + 1];  // +1 for sentinel

    for (int i = 0; i < l_sz; i++) {
        L[i] = a[i + l];
    }

    for (int i = 0; i < r_sz; i++) {
        R[i] = a[mid + 1 + i];
    }

    // Sentinel values to simplify comparisons
    L[l_sz] = R[r_sz] = INT_MAX;

    int l_i = 0, r_i = 0;
    for (int i = l; i <= r; i++) {
        if (L[l_i] < R[r_i]) {
            a[i] = L[l_i++];
        } else {
            a[i] = R[r_i++];
        }
    }
}

/**
 * @brief Recursively sorts the array `a` using Merge Sort algorithm.
 * 
 * The function divides the array into halves, sorts each half, and merges them.
 * 
 * @param l Left index of the segment to be sorted.
 * @param r Right index of the segment to be sorted.
 */
void mergeSort(int l, int r) {
    if (l == r) return;

    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r, mid);
}

/**
 * @brief Main function to read input, sort using merge sort, and print the result.
 * 
 * Reads `n` elements into the array `a`, sorts them using `mergeSort`, and prints
 * the sorted array to standard output.
 */
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
