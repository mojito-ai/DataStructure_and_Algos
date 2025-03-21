class Solution {
public:
    int pf[100+10];
    int subarraySum(vector<int>& nums) {
        for (int i = 0; i<nums.size(); i++) {
            pf[i+1] = nums[i] + pf[i];
        }

        int sum = 0;
        for(int i = 0; i<nums.size(); i++) {
            int start = max(0, i-nums[i]);
            sum += pf[i+1] - pf[start];
        }

        return sum;
    }
};