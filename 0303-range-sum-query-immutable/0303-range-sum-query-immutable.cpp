class NumArray {
public:
    const static int N = 1e4 + 10;
    static int pf[N]; // Declare static array
    NumArray(vector<int>& nums) {
        // Calculating Prefix Sum
        for(int i = 1; i<=nums.size(); i++) {
            pf[i] = pf[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return pf[right+1] - pf[left];
    }
};

int NumArray::pf[NumArray::N] = {0};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */