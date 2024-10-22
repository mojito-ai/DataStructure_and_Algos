/**
 * https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1
 * 
 * 
 * A string str is given to represent a positive number. The task is to round str to the nearest multiple of 10.  If you have two multiples equally apart from str, choose the smallest element among them.
 * Examples:
 * 
 * Input: str = 29 
 * Output: 30
 * Explanation: Close multiples are 20 and 30, and 30 is the nearest to 29. 
 * 
 * Input: str = 15
 * Output: 10
 * Explanation: 10 and 20 are equally distant multiples from 20. The smallest of the two is 10.
 * 
 * Expected Time Complexity: O(n).
 * Expected Auxiliary Space: O(1).
 * 
 * Constraints:
 * 1 <= str.size()<= 105
 * 
 */ 


#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;
    
    int n = s.size();
    // If last digit is <=5 the simply make the last digit 0
    if (s[n-1] <= '5') {
        s[n-1] = '0';
    } else {
        s[n-1] = '0';
        int i;

        // There will be cases where carry will be there. e.g. 9999999. 
        // In these cases, we will keep making 0, till the digit is not 9
        for (i=n-2; i>=0; i--) {
            if(s[i]!='9') {
                break;
            } else {
                s[i] = '0';
            }
        }

        if (i<0) {
            // means all digits were 9
            s = '1' + s;
        } else {
            // just increment the digit before 0
            s[i]++;
        }
    }

    return s;
}