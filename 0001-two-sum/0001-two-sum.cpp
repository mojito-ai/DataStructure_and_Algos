class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Create a vector of pairs to keep track of original indices
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); i++) {
            indexedNums.push_back({nums[i], i});
        }
        
        // Sort the indexedNums based on the values
        sort(indexedNums.begin(), indexedNums.end());

        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            int sum = indexedNums[i].first + indexedNums[j].first;
            if (sum == target) {
                // Return the original indices
                return {indexedNums[i].second, indexedNums[j].second};
            } else if (sum < target) {
                i++; // Move the left pointer to the right to increase the sum
            } else {
                j--; // Move the right pointer to the left to decrease the sum
            }
        }
        
        return {}; // Return an empty vector if no solution is found
    }
};