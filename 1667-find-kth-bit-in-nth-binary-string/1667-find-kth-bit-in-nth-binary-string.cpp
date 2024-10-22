class Solution {
public:
    char findKthBit(int n, int k) {
        // Base Case
        if (n==1) return '0';

        // length is 2^n - 1
        int length = pow(2,n) - 1; // (1 << n) - 1;
        
        int mid = length/2 + 1;

        // If k is the middle position, return '1'
        if (k == mid) return '1';

        if (k < mid) {
            // If k is in the first half, find the bit in Sn-1
            return findKthBit(n-1, k);
        }
        else {
            // If k is in the second half, find the bit in Sn-1 and invert it
            return findKthBit(n-1, length-k+1) == '0' ? '1' : '0';
        }
    } 
};