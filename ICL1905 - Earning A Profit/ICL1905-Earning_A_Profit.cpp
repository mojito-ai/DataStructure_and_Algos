// https://www.codechef.com/problems/ICL1905

/**
 * 
 * Earning A Profit
There are N planets numbered 1 to N. You are a space merchant who earns by selling goods on these planets. Traveling to each planet requires you to pay for the fuel. The difficulty of traveling to 
i-th planet is Di. You need to plan your trip by choosing a consecutive sub segment of planets.

Your earning of the trip is calculated as follows -

1. You earn A coins for every planet you visit.
2. For each planet i you visit, you have to pay Ci coins for the fuel.
3. If you visit every planet with indices L to R, you also have to pay gap(L,R) coins where gap(L,R) = max[(Dr - Dl)^2] for L<=l<=r<=R

Calculate the maximum profit you can earn by traveling to a consecutive segment of planets. Note that if you travel to no planet at all, your net profit will be zero.

###Input:

First line will contain T, number of testcases. Then the testcases follow.
For each testcase, the first line contains two integers N & A
The next N lines contains two integers Ci and Di
 
###Output: For each testcase, output a single integer denoting the maximum profit you can earn.

###Constraints

1<=T<=10
1<=N<=3000
1<=A<=1e6
1<=D,C<=1e6
 
###Sample Input:
1 
3 10 
1 3 
3 1 
2 2

###Sample Output: 20

###EXPLANATION: For L = 1 and R = 3, we have profit = (3 - 1 + 1) * 10 - (1 + 3 + 2) - (3 - 1)*(3 - 1) = 20. This is the maximum possible profit for any sub-segment.
 * 
 */ 

#include <bits/stdc++.h>
using namespace std;

const int T = 3000;
//Prefix array for gap
long long gap[T+10][T+10];
// Prefix array for a-coin
int pf[T+10];

int main() {
	int t;
	cin >> t;
	while (t--){
	    int N,A;
	    cin >> N >> A;
	    int coin[N+1], dist[N+1];
	    for (int i = 1; i<=N; i++) {
	        cin >> coin[i] >> dist[i];
	    }
	    
	    for(int i = 1; i<=N; i++) {
	        pf[i] = pf[i-1] + (A-coin[i]);
	    }
	    
	    for(int i = 1; i<=N; i++) {
	        for(int j = i; j<=N; j++) {
	            // Now we are calculating the gap for every subarray.
	            // So lets say we are calculating for 1->3 then its the max(1-3, 1-2, 2-3);
	            gap[i][j] = (dist[j]-dist[i]) * 1LL * (dist[j]-dist[i]);
	        }
	    }
	    
	    for(int i = N; i>=1; i--) {
	        for(int j = i; j<=N; j++) { // Moving rightwards
	            // Now we are calculating the gap for every subarray.
	            // So lets say we are calculating for 1->3 then its the max(1-3, 1-2, 2-3);
	            // So what I do is traverse the 2-D array starting bottom row and calculate max and move forward
	            // E.g. the max for (1,4) would be max(1,1 | 1,2 | 1,3 | 1,4 | 2,2 | 2,3 | 2,4 | 3,3 | 3,4 | 4,4)
	            // Also these pairs are a function of no-order | replace sampling table -> (N+k-1Ck)
	            gap[i][j] = max(gap[i][j], max(gap[i+1][j], gap[i][j-1]));
	        }
	    }
	    
	    long long profit = 0;
	    
	    for(int i=1; i<=N; i++) {
	        for(int j=i; j<=N; j++) { // Traversing all subarrays
	            profit = max(profit,pf[j]-pf[i-1]-gap[i][j]);
	        }
	    }
	    
	    cout << profit << endl;
	}

}
