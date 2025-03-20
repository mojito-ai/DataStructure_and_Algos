/**
 * 
 * https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/xsquare-and-double-strings-1/
 * 
 * Problem
 * Xsquare got bored playing with the arrays all the time. Therefore, he has decided to play with the strings. Xsquare called a string P a "double string" if string P is not empty and can be broken into two strings A and B such that A + B = P and A = B. for eg : strings like "baba" , "blabla" , "lolo" are all double strings whereas strings like "hacker" , "abc" , "earth" are not double strings at all.
 * 
 * Today, Xsquare has a special string S consisting of lower case English letters. He can remove as many characters ( possibly zero ) as he wants from his special string S. Xsquare wants to know , if its possible to convert his string S to a double string or not.
 * 
 * Help him in accomplishing this task.
 * 
 * Note :
 * 
 * Order of the characters left in the string is preserved even after deletion of some characters.
 * 
 * Input :
 * First line of input contains a single integer T denoting the number of test cases. First and the only line of each test case contains a string S denoting Xsquare's special string.
 * 
 * Output :
 * For each test case, print "Yes" if it is possible to convert the given string to a double string. Print "No" otherwise.
 * 
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int nums[26] = {0};
        bool flag = false;
        // Algorithm A=B means every char in A is in B
        // It means that if I have even 1 pair of repeating chars
        // Then I can construct a special string by removing all other chars. 
        for (int i = 0; i<s.size(); i++) {
            nums[s[i]-'a']++;
            if(nums[s[i]-'a'] == 2) {
                flag = true;
                break;
            }
        }

        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}