class NumArray {
public:
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums; // Correct assignment
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for (;left<=right; left++) {
            sum += nums[left];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */