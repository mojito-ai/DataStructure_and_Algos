/**
 * https://codeforces.com/contest/1426/problem/D
 * 
 * D. Non-zero Segments
 * 
 * Kolya got an integer array 𝑎1,𝑎2,…,𝑎𝑛
. The array can contain both positive and negative integers, but Kolya doesn't like 0
, so the array doesn't contain any zeros.

Kolya doesn't like that the sum of some subsegments of his array can be 0
. The subsegment is some consecutive segment of elements of the array.

You have to help Kolya and change his array in such a way that it doesn't contain any subsegments with the sum 0
. To reach this goal, you can insert any integers between any pair of adjacent elements of the array (integers can be really any: positive, negative, 0
, any by absolute value, even such a huge that they can't be represented in most standard programming languages).

Your task is to find the minimum number of integers you have to insert into Kolya's array in such a way that the resulting array doesn't contain any subsegments with the sum 0
.

Input
The first line of the input contains one integer 𝑛
 (2≤𝑛≤200000
) — the number of elements in Kolya's array.

The second line of the input contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (−109≤𝑎𝑖≤109,𝑎𝑖≠0
) — the description of Kolya's array.

Output
Print the minimum number of integers you have to insert into Kolya's array in such a way that the resulting array doesn't contain any subsegments with the sum 0
.

Examples
InputCopy
4
1 -5 3 2
OutputCopy
1
InputCopy
5
4 -2 3 -9 2
OutputCopy
0
InputCopy
9
-1 1 -1 1 -1 1 1 -1 -1
OutputCopy
6
InputCopy
8
16 -5 -11 -15 10 5 4 -4
OutputCopy
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        long long pf[N+1] = {0};


        // Insight: If in a big subarray, there is a small subarray of sum 0 
        // then it can compensate for all
        // Map to track prefix sum frequency
        unordered_map<long long, int> mp;
        mp[0] = 1; // To handle first subarray in case it sums to 0

        int count = 0;
        
        for (int i = 0; i<N; i++) {
            cin >> arr[i];
            pf[i+1] = arr[i] + pf[i];
            // If this prefix sum has been seen before, it means a subarray sum is zero
            if (mp[pf[i + 1]] > 0) {
                count++; // Need to add an element
                mp.clear(); // Reset map (removing all stored prefix sums)
            }
            mp[pf[i + 1]] = 1;
            mp[pf[i]] = 1;
        }

        /* Algorithm for finding max integers needed in case we have to feed only 1 integer everywhere
        
        unordered_map<int, int> mp;
        int count = 0;

        for (int i = 0; i<N; i++) {
            cin >> arr[i];
            pf[i+1] = arr[i] + pf[i];
            mp[pf[i+1]]++;
        }

        for(auto &p : mp) {
            if (p.second >= 2) {
                count += (p.second * (p.second-1))/2;
            }
        }

        */

        cout << count << endl;
    }

}

//   -1 1 -1 1 -1 1 1 -1 -1
// 0 -1 0 -1 0 -1 0 1  0 -1
  
