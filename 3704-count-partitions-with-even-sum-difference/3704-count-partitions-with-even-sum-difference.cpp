class Solution {
public:
    int pf[100+10];
    int countPartitions(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++) {
            pf[i+1] = nums[i] + pf[i];
        }

        int count = 0;
        for (int i = 1; i<nums.size(); i++) {
            if((pf[nums.size()]-2*pf[i])%2==0) count++;
        }

        return count;
    }
};