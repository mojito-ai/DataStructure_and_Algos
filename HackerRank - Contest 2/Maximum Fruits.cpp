#include <bits/stdc++.h>
using namespace std;

/**
 *
 * You have given N plates each plate contains some number of fruits. You will be given Q queries of type: add X number of fruits in each plate from L to R.

Input:

First line of input contains N, number of plates.

Next line contains N integers, number of fruits in each plate.

Third line will contain Q, number of queries.

Next Q lines follow queries of any of the following type: X L R.

Output:

After completing all the queries, print the maximum number of fruits among all the plates.

Constraints:

1<=N<=10^5;

1<=Q<=10^5;

0<=L<=R<N;

1<=X<=100;

 */

// Maximum Fruits
/**
 * Algorithm: ScanLine Algorithm
 */ 

const int T = 1e5;
int pf[T+10];
int arr[T+10];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i<=N; i++) {
        cin >> arr[i];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int X,L,R;
        cin >> X >> L >> R;
        L++; R++; //converting 0 based to 1 based
        pf[L] += X;
        pf[R+1] -= X;
    }

    for (int i = 1; i<=N; i++) {
        pf[i] += pf[i-1];
        arr[i] += pf[i];
    }

    cout << *max_element(arr+1, arr+N+1) << endl;

    
}