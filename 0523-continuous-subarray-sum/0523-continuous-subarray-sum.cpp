class Solution {
public:
    const static int M = 1e5+10;
    int pf[M];
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        
        pf[0] = 0;
        pf[1] = nums[0];
        for(int i=1; i<nums.size(); i++) {
            pf[i+1] = nums[i] + pf[i];
            if (pf[i+1] % k == 0) return true; //Checking from 0 index for all subarray >= 2
        }

        return optimised(nums, k);
    }

    // Have a hashmap to store pf[i]%k. If both pf[i] and pf[j] give the same remainder when divided by k, their difference must be a multiple of k.
    bool optimised(vector<int>& nums, int k) {
    unordered_set<int> mp;
    int prefixSum = 0;
    int prevMod = 0; // Stores the remainder from one step before (to ensure subarray length >= 2)

    for (int num : nums) {
        prefixSum += num;
        int mod = prefixSum % k;

        // Handle negative remainder case
        if (mod < 0) mod += k; 

        if (mp.find(mod) != mp.end()) return true; 

        mp.insert(prevMod); // Insert previous remainder (ensures subarray length >= 2)
        prevMod = mod;
    }

    return false;
}

    // Brute Force: Check for each subarray of size 2 and greater. 
    bool checkRecursion(vector<int>& nums, int k, int i, int j) {
        if (j-i < 2) return false;

        if (j == nums.size()+1) return false;

        int sum = pf[j]-pf[i];

        if (sum % k == 0) return true;
        else return checkRecursion(nums,k,i+1, j) || checkRecursion(nums,k,i, j+1);
    }
};