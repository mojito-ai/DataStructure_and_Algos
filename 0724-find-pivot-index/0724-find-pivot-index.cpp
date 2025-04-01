class Solution {
public:
    static const int M = 1e4;
    int fwd[M+10];
    int bwd[M+10];
    int pivotIndex(vector<int>& nums) {
        for(int i = 1; i<=nums.size(); i++) { // 1-based indexing
            fwd[i] = nums[i-1] + fwd[i-1];
            bwd[nums.size()-i+1] = nums[nums.size()-i] + bwd[nums.size()-i+2];
        }

        for(int i = 1; i<=nums.size(); i++) {
            if (fwd[i-1] == bwd[i+1]) return i-1;
        }

        return -1;
    }
};