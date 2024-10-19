/**
 * 
 * Link: https://www.hackerrank.com/challenges/printing-pattern-2/problem
 * 
 * Print a pattern of numbers from  to  as shown below. Each of the numbers is separated by a single space.
 *
 *  4 4 4 4 4 4 4  
 *  4 3 3 3 3 3 4   
 *  4 3 2 2 2 3 4   
 *  4 3 2 1 2 3 4   
 *  4 3 2 2 2 3 4   
 *  4 3 3 3 3 3 4   
 *  4 4 4 4 4 4 4   
 * 
 * Input Format
 * The input will contain a single integer .
 * 
 * 1 <= n <= 1000
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i=1; i<=2*n-1; i++) {
        for (int j=1; j<=2*n-1; j++) {
            int x = max(abs(n-i), abs(n-j)) + 1;
            cout << x << " ";
        }
        cout << endl;
    }
}