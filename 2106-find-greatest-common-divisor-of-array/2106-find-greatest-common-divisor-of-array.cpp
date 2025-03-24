class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = INT_MAX;
        int large = INT_MIN;

        for(int n: nums) {
            small = min(small, n);
            large = max(large, n);
        }

        return __gcd(small, large);
    }
};