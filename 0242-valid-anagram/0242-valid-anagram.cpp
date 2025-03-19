class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        return approach2(s, t);
    }

    // Sorting based approach
    bool approach1(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    // hashset
    bool approach2(string s, string t) {
        unordered_map<char, int> mp;
        
        for (char c : s) {
            mp[c]++;  // Increment count of each character in s
        }

        for (char c : t) {
            if (mp.find(c) == mp.end() || mp[c] == 0) {
                return false;  // If character is missing or count is 0, return false
            }
            mp[c]--;  // Decrement count for matched character
        }

        return true;
    }

};