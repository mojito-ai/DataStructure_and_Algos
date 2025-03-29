#include <bits/stdc++.h>
using namespace std;

/**
 *
 * Joe is not good with strings, so you volunteer for his help in his task with strings.

Given a string(consisting of small case alphabets only), we need to find the length of largest possible palindrome for all queries , where each query contains an integer N , and the next line of the query includes N space seperated lowercase alphabets.You must keep the following things in mind:

1. For each query, you can use only the characters mentioned in the query to form the palindrome string.

2.Palindromic string can be produced using the alphabets of the input string in any order.

 

INPUT FORMAT -

First line contains the string.

The next line takes as input an integer q(denoting the number of queries).

For each query -

The first line contains an integer N denothing number of alphabets.

Next line consist of N space seperated alphabets(alphabets maybe repeated but yet you need to consider them once only).

 

OUTPUT FORMAT-

For each query, print the maximum size of palindrome possible only using the alphabets given in the query.

 

CONSTRAINS-

1≤|S|≤10000

1≤q≤10000

1≤N≤26

 

For 40 points -

1≤|S|≤10000

1≤q≤10

1≤N≤26

 

For 60 points -

Original Constraints
 */

// Help Joe
/**
 * Algorithm: Palindrome
 * 
 * 1. All chars should be odd in number with at max one char occurring odd times.
 * Since we dont have to use all chars - use all chars of even.
 * * In case its odd number of occurance, then only use its even chars and at the end add 1. 
 */ 

const int T = 26;
int hsh[T];

int main() {
    string s;
    cin >> s;
    for(char c: s) {
        hsh[c-'a']++;
    }
    int q;
    cin >> q;
    while (q--) {
        int N;
        cin >> N;
        
        unordered_set<int> alpha;
        for (int i = 0; i < N; i++) {
            char temp;
            cin >> temp;
            alpha.insert(temp - 'a'); // Store unique characters from the query
        }

        int count_odd = 0;
        int count = 0;
        for(int p: alpha) {
            if (hsh[p]%2 == 0) count += hsh[p];
            else {
                count_odd = 1;
                count += hsh[p]-1;
            }
        }

        cout << count + count_odd << endl;

    }
}