/**
 * 
 * https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21
 * 
 * Given a string s, return the maximum number of unique substrings that the given string can be split into.
 * 
 * You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.
 * A substring is a contiguous sequence of characters within a string.
 * 
 * Example 1:
 * Input: s = "ababccc"
 * Output: 5
 * Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.

 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return splitter(s, 0, seen);
    }

private: 
    int splitter(const string &s, int start, unordered_set<string> &seen) {
        if (start == s.size()) return 0;

        int maxSize = 0;

        for (int end = start+1; end <= s.size(); end++) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxSize = max(maxSize, 1 + splitter(s, end, seen));
                seen.erase(substring);
            } 
        }

        return maxSize;
    }
};