/**
 * 
 * GCD Queries; A problem from Code chef. You are given an 
 * array A of integers of size N. You will be given Q queries where each query is represented by two integers L, R. 
 * You have to find the gcd(Greatest Common Divisor) of the array after excluding the part from range L to R inclusive (1 Based indexing). 
 * You are guaranteed that after excluding the element, you will be left with non-zero length of array.
 * 
 * 
 * Input: 
 * 1
 * 3 3
 * 2 6 9
 * 1 1
 * 2 2
 * 2 3
 * 
 * Output: 
 * 3
 * 1
 * 2
 */

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N,Q;
        cin >> N >> Q;

        int arr[N+10];
        for (int i = 1; i<=N; i++) {
            cin >> arr[i]; 
        }

        // as L & R are 1 based indexing
        int fwd_gcd[N+10] = {0};
        int rev_gcd[N+10] = {0};

        for(int i = 1; i<=N; i++) {
            fwd_gcd[i] = __gcd(fwd_gcd[i-1], arr[i]);
        }

        for(int i = N; i>=1; i--) {
            rev_gcd[i] = __gcd(rev_gcd[i+1], arr[i]);
        }
    
        while (Q--) {
            int l,r;
            cin >> l >> r;
            cout << __gcd(fwd_gcd[l-1], rev_gcd[r+1]) << endl; 
        }
    }
}