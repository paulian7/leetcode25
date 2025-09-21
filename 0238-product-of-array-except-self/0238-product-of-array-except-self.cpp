class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // tech: 
            // prefix * postfix = total product except the curr element 
        
        // time & space comp: 
            // time: o(n) 
            // space: o(n)
        
        // 1. declare & initialize result array 
        vector<int> res(nums.size(), 1);

        // 2. prefix technique 
        int prefixVal = 1; 
        for(int i = 0; i < nums.size(); i++)
        {
            res[i] = prefixVal; 
            prefixVal *= nums[i];
        }

        // 3. postfix technique 
        int postfixVal = 1; 
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            res[i] *= postfixVal; 
            postfixVal *= nums[i]; 
        }

        return res;
    }
};