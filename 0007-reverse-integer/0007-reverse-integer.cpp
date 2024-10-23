class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;  // Get the last digit
            x /= 10;           // Remove the last digit

            // Check for overflow/underflow before updating `rev`
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;  // Append the digit to `rev`
        }
        return rev;
    }

    int reverseBruteForce(int x) {
        
        string s = to_string(x);
        string rev;
        int i=0;

        if (s[0] == '-') {
            i = 1;
        }

        while (i<s.size()) {
            rev.insert(0, 1, s[i++]);
        }

        if (s[0] == '-') {
            rev.insert(0, 1, s[0]);
        }

        try {
            return stoi(rev);
        } catch (exception e) {
            return 0;
        }
    }
};