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