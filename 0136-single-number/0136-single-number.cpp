class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        Using XOR property
        a b a^b
        0 0  0
        0 1  1
        1 0  1
        1 1  0
        
        a^a = 0
        a^0 = a
        a^b^b = a
        */

        int single = 0;
        for (int n : nums) {
            single = single^n;
        }

        return single;
    }
};