/**
 * Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/?envType=daily-question&envId=2024-10-19
 * 
 * Given two positive integers n and k, the binary string Sn is formed as follows:
 * S1 = "0"
 * Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
 * Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).
 * For example, the first four strings in the above sequence are:
 * 
 * S1 = "0"
 * S2 = "011"
 * S3 = "0111001"
 * S4 = "011100110110001"
 * Return the kth bit in Sn. It is guaranteed that k is valid for the given n.
 * 
 * /

class Solution {
public:
    char findKthBit(int n, int k) {
        string ans = "0";
        if (n!=1) {
            while(--n) {
                ans = ans + '1' + reverse_invert(ans);
            }
        }
        cout << ans;
        return ans[k-1];
    }

    string reverse_invert(string& str) {
        string reverse_invert;
        for(int i=str.size()-1; i>=0; i--) {
            if (str[i] == '0')
                reverse_invert.push_back('1');
            else 
                reverse_invert.push_back('0');
        }
        return reverse_invert;
    }
};