class Solution {
public:
    bool checkRecord(string s) {
        int absent=0;

        for (int i=0; i<=s.size()-1; i++) {
            
            if (s[i] == 'A') {
                absent++;
                if (absent >= 2)
                    return false;
            } else if (s[i] == 'L' && i <= s.size()-3 && s[i+1] == 'L' && s[i+2] == 'L') {
                return false;
            }
        }

        return absent < 2 ? true : false; 
     }
};