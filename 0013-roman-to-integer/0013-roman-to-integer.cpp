class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashmap;
        // Populate the Roman numeral values
        hashmap['I'] = 1;
        hashmap['V'] = 5;
        hashmap['X'] = 10;
        hashmap['L'] = 50;
        hashmap['C'] = 100;
        hashmap['D'] = 500;
        hashmap['M'] = 1000;

        int ans=0;
        // Iterate through the string
        for (int i = 0; i < s.size(); i++) {
            // Check if the current character represents a smaller number before a larger one
            if (i < s.size() - 1 && hashmap[s[i]] < hashmap[s[i + 1]]) {
                ans -= hashmap[s[i]];  // Apply subtraction rule
            } else {
                ans += hashmap[s[i]];
            }
        }

        return ans;
    }
};