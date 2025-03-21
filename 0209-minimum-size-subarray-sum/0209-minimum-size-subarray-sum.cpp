class Solution {
public:
    const static int M = 1e5+10;
    int pf[M];
    int minSubArrayLen(int target, vector<int>& nums) {
        for (int i = 0; i<nums.size(); i++) {
            pf[i+1] = nums[i] + pf[i];
        }

        // Use two pointer approach where i points to start and j points to end
        // Now do pf[j] - pf[i] -> If is still > target, try switching to i++ as all +ve numbers
        // If < target then do j-- 
        
        int ans = INT_MAX;
        int i = 0, j = 1;  // j should start from 1 (since pf[0] = 0)

        while (j <= nums.size()) {
            int temp = pf[j] - pf[i];

            if (temp >= target) {
                ans = min(ans, j - i);
                i++;  // Shrink the window from the left
            } else {
                j++;  // Expand the window from the right
            }
        }

        return (ans == INT_MAX) ? 0 : ans;  // If no valid subarray found, return 0
    }
};