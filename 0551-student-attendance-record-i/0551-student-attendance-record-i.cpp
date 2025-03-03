class Solution {
public:
    bool checkRecord(string s) {
        int absent=0;
        bool late=0;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'A') 
                absent ++;

            if (s[i] == 'L' && i <= s.size()-3 && s[i+1] == 'L' && s[i+2] == 'L') {
                i = i+2;
                return false;
            }
        }

        return absent < 2 ? true : false; 
     }
};