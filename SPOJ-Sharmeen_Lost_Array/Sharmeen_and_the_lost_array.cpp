/**
 * MOZSATLA - Sharmeen and the Lost Array
no tags 

Sharmeen loves array very much. Many days ago she wrote an array (of n elements and the index of this array is 1 based) in her notebook, but unfortunately she lost the notebook. She want to restore the array. The only clue she know that is if in any position(i) of the array (1<= i < n), the element in this position is greater than, equal or less than the next position(i+1) element.

Can you help her to restore the array?

Input
In the first line given an integer t (1 <= t <= 100), which is the number of test cases.

For each test case,

In the first line there will be given a positive integer n (1 <= n <= 105) which is the size of the lost array. In the next line there will be n - 1 integers Xi (0 <= Xi <= 2).

If, Xi = 0, then ith  element is equal to (i+1)th element of the lost array.

If, Xi = 1, then ith  element is less than (i+1)th element of the lost array.

If, Xi = 2, then ith  element is greater than (i+1)th element of the lost array.

Output
For each test case you have to output the lost array in one line. If multiple solution exist then you have to print the lexicographically smallest one. Elements of the lost array must be greater than zero.

For better understanding see the sample input output.

Input:
10
5
1 1 1 1
5
1 2 0 1
10
2 2 2 1 0 1 0 2 2
1
2
1
2
0
2
2
10
1 1 2 2 0 0 1 0 0
4
1 0 0
9
2 2 2 2 1 0 2 2


Output:
1 2 3 4 5 
1 2 1 1 2 
4 3 2 1 2 2 3 3 2 1 
1 
1 2 
1 1 
2 1 
1 2 3 2 1 1 1 2 2 2 
1 2 2 2 
5 4 3 2 1 3 3 2 1 
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> arr(N - 1);
    vector<int> A(N, 1); // Initialize the sequence with 1s

    for (int i = 0; i < N - 1; i++) {
        cin >> arr[i];
    }

    // Right-to-left traversal to fix values
    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] == 0) {
            A[i] = A[i + 1];  // Copy next value
        } 
        else if (arr[i] == 1) {
            A[i] = 1; // Start with 1
            if (A[i + 1] == 1) {
                int l = i + 1;
                A[l]++; // Increment the next value
                while (l < N - 1) {
                    if (arr[l] == 0) {
                        A[l + 1] = A[l]; // Copy if '0'
                    } 
                    else if (arr[l] == 1 && A[l + 1] <= A[l]) {
                        A[l + 1]++; // Ensure it's increasing
                    } 
                    else {
                        break;
                    }
                    l++;
                }
            }
        } 
        else {  // arr[i] == 2
            A[i] = A[i + 1] + 1;  // Ensure increasing pattern
        }
    }

    // Print the result
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
