#include <bits/stdc++.h>
using namespace std;

/**
 *
 * A global pandemic is on the rise. But, somehow a vaccine came to rescue the people in despair. However some of the vaccines available are 'incorrect' (i.e. not upto the mark) and doesn't cure the infected person. Your job is to identify the total number of 'incorrect vaccines' from a grid of available vaccines. 
 * An "incorrect vaccine" is one which has an odd number printed on it. All the other vaccine are assumed to be correct.

You will be given a grid of size M X N containing integers and Q queries where each query contains four integers - l1, r1, l2, r2.  For each query you need to answer the number of incorrect vaccines from index (l1, r1) to (l2, r2) in the grid.

Can you help the people and save the world !!

Note: Assume 1-based indexing.

 

Input:

First Line  contains two integers M and N, where M and n are the number of rows and columns in the grid respectively.

Next M lines each contain N space-separated integers each representing the vaccine numbers on ith row of the grid.

Next line contains an integer Q, the number of queries.

Next Q lines contains four integers - l1, r1, l2, r2 representing the coordinates of the grid within which you need to find the number of incorrect vaccines.

 

Output:

Print the number of incorrect vaccines for each query in a new line.

 

Constraints:

1 <= N <= 103

1 <= M <= 103

1 <= Ai <= 109

 

Sample Test Case:

Input:

3 3
1 1 1 
1 2 1
1 1 1
4
1 1 3 3
1 2 1 2
2 2 3 3
2 2 2 2

 

Output:

8

1

3

0
 * 
 * 
 * 
 * 
 * 
 */

// Vaccination Time
/**
 * Algorithm
 * 
 * Let pf[i][j] be the # of incorrect vaccines from node 0,0 to i,j
 * So the # of healthy vaccines btw (l1,r1) and (l2,r2)
 * 
 * pf[i][j] = (1/0 based if curr is incorrect/correct) + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
 * 
 * Ans = pf[l2][r2] - pf[l1-1][r2] - pf[l2][r1-1] + pf[l1-1][r1-1]
 * 
 */ 

const int T = 1e3;
int pf[T+10][T+10];

int main() {
    int M, N;
    cin >> M >> N;
    for (int i = 1; i<=M; i++) {
        for (int j = 1; j<=N; j++) {
            int temp, incorrect = 0;
            cin >> temp;
            if (temp%2 != 0) incorrect = 1;
            pf[i][j] = incorrect + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << pf[l2][r2] - pf[l1-1][r2] - pf[l2][r1-1] + pf[l1-1][r1-1] << endl;
    }
}