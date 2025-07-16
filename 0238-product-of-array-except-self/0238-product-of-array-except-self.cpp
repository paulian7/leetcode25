class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1); 

        // first pass forward - calculating prefix part of the prefix * postfix 
        int prefixVal = 1; 
        for(int i = 0; i < nums.size(); i++)
        {
            result[i] = prefixVal; 

            // update prefixVal 
                // as it gets the culumative product up to our current element 
            prefixVal *= nums[i]; 
        }

        // second pass - but backwards - as it calculates the postfix 
        int postfixVal = 1; 
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            result[i] *= postfixVal; 
            postfixVal *= nums[i]; 
        }

        return result; 
    }
};