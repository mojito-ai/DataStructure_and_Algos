#include <bits/stdc++.h>
using namespace std;

/**
 *
 * Problem
You are given an array A of size. You have to find out number of ordered triplet(i,j,k) such that 
abs(A[i] - A[j]) = abs(A[j] - A[k]) where abs represents absolute value.

Input:

First Line contains N representing size of array.

Next line contains n space separated integers representing array A
.

Output:

Print the number of ordered triplets satisfying above conditioned modulo 10^9 + 7 as answer will be large.
 
1 <= N <= 10^5
1 <= A[i] <= 10^3

Input: 
5
2 4 5 2 2

Answer: 18
1,4,5
1,5,4
4,1,5
4,5,1
5,1,4
5,4,1

1,2,4
1,2,5
4,2,1
4,2,5
5,2,1
5,2,4

1,3,4
1,3,5
4,3,1
4,3,5
5,3,1
5,3,4
 */

// Ordered Triplets
/**
 * Algorithm: 
 */ 

const int T = 1e5;
const int Z = 1e3;
int pf[Z+10];
int arr[T+10];
const int MOD = 1e9+7;

// Triple loop
void brute_force() {
    int N;
    cin >> N;
    for (int i = 0; i<N; i++) {
        cin >> arr[i];
    }
    
    int count = 0;
    
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            if (i==j) continue;
            for (int k = 0; k<N; k++) {
                if (i==k || j==k) continue;
                if (abs(arr[i] - arr[j]) == abs(arr[j] - arr[k])) {
                    count = (count % MOD + 1 % MOD)%MOD;
                }
            }
        }
    }

    cout << count << endl;    
}

// What we are doing is counting
/**
 * What we are doing is combinatorics where we take 1st element then 2nd
 * Try to see k1 = j + abs(i-j) and its freq
 * Try to see k2 = j - abs(i-j) and its freq
 * 
 * In case k1 = k2 then we only need to count once cti * ctj * ctk1
 * otherwise k1 != k2 then take both cases cti * ctj * ctk1 + cti * ctj * ctk2
 * 
 */ 
void prefix_optimised() {
    int N;
    cin >> N;
    for (int i = 0; i<N; i++) {
        cin >> arr[i];
        pf[arr[i]]++;
    }
    
    long long count = 0;

    for(int i = 1; i<=Z; i++) {
        if (pf[i] == 0) continue;
        long long cti = pf[i]--;
        for(int j = 1; j<=Z; j++) {
            if (pf[j] == 0) continue;
            long long ctj = pf[j]--;
            int absolute = abs(i - j);
            int ctk1 = (j + absolute <= Z) ? pf[j + absolute] : 0;
            int ctk2 = (j - absolute >= 1) ? pf[j - absolute] : 0;

            if (ctk1 == ctk2) {
                count += (1LL * cti * ctj * ctk1) % MOD;
            } else {
                count += (1LL * cti * ctj * ctk1) % MOD;
                count += (1LL * cti * ctj * ctk2) % MOD;            
            }
            pf[j]++;
        }
        pf[i]++;
    }

    cout << count << endl;
}

int main() {
    prefix_optimised();
    // brute_force();
}