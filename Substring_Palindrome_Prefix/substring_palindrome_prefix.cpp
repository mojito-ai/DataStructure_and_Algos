/**
 * Given a String S and two integers L & R, we want
 * to know whether all the letters of the substring
 * L & R (both included) can be rearranged to form
 * a palindrome or not. We want to know for Q values
 * of L & R.
 * 
 *  2
    5 5
    abcec
    1 2
    2 5
    3 5
    1 5
    1 4
    5 5
    aabbc
    1 2
    2 5
    3 5
    1 5
    2 4

    Output: 

    NO
    NO
    YES
    NO
    NO
    YES
    NO
    YES
    YES
    YES
 */ 

#include <bits/stdc++.h>
using namespace std;

/**
 * Make a prefix sum for each char individually
 * Then for each char, find its # of occurance in its own pf array.
 */
void optimised_approach(){
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        int hsh[26][N+1]; // pf sum for each char

        // Resetting hash array
        for (int i = 0; i<26; i++) {
            for (int j = 0; j<=N; j++) {
                hsh[i][j] = 0;
            }
        }

        string S;
        cin >> S;

        // Counting occurances
        for (int i = 0; i<N; i++) {
            hsh[S[i]-'a'][i+1]++; // 1 based indexing
        }

        // Prefix Sum
        for (int i = 0; i<26; i++) {
            for (int j = 1; j<=N; j++)
                hsh[i][j] += hsh[i][j-1];
        }

        while(Q--) {
            int L, R;
            cin >> L >> R;

            int oddCt = 0;
            for(int i = 0; i<26; i++) {
                int charCt = hsh[i][R] - hsh[i][L-1];
                if (charCt%2 != 0) {
                    oddCt++;
                    if (oddCt > 1) break;
                }
            }

            oddCt <= 1 ? cout << "YES" << endl : cout << "NO" << endl;
        }
    }
}


/**
 * We know that a word is palindrome in 2 cases
 * 1. Either it has all chars in even pairs
 * 2. All chars in even pairs and only 1 single element
 *  
 * So if num of elements with odd occurrances > 1 then palindrome not possible
 */ 
void brute_force() {
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        string S;
        cin >> S;
        while(Q--) {
            int alphabets[26] = {0}; // Hashing
            int L, R;
            cin >> L >> R;
            // string temp = S.substr(L-1, R-L+1);
            for (int i = L-1; i <= R-1; i++) {
                alphabets[S[i]-'a']++;
            }

            int ctOdd = 0;
            for(int x: alphabets) {
                if (x%2 != 0) {
                    ctOdd++;
                    if (ctOdd > 1) break;
                }
            }

            ctOdd <= 1 ? cout << "YES" << endl : cout << "NO" << endl;
        }
    }
}

int main() {
    optimised_approach();
    // brute_force();
}