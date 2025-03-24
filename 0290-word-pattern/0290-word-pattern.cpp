class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> arr; // To store the split parts

        stringstream ss(s);
        string temp;

        while (ss >> temp) {  // Extract words separated by spaces
            arr.push_back(temp);
        }    

        if (arr.size() != pattern.size()) return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;

        for (int i = 0; i<pattern.size(); i++) {
            char c = pattern[i];
            string str = arr[i];

            if (mp.find(c) != mp.end()) { 
                if (mp[c] != str) return false;  
            } else {
                mp[c] = str;
            }

            if (mp2.find(str) != mp2.end()) { 
                if (mp2[str] != c) return false;
            } else {
                mp2[str] = c;
            }
        }

        return true;
    }
};