class Solution {
public:
    int reverse(int x) {
        
        string s = to_string(x);
        string rev;
        int i=0;

        if (s[0] == '-') {
            i = 1;
        }

        while (i<s.size()) {
            rev = s[i] + rev;
            i++;
        }

        if (s[0] == '-') {
            rev = "-" + rev;
        }

        try {
            return stoi(rev);
        } catch (exception e) {
            return 0;
        }
    }
};