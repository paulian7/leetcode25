class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix technique 
            // time: 
            // space: 
        
        // prefix sums - interate from start -> end 

        // want to declare array to return as result
        vector<int> res(nums.size(), 1); 
        int prefixVal = 1; 
        for(int i = 0; i < nums.size(); i++)
        {
            res[i] = prefixVal; 

            prefixVal *= nums[i]; 
        }

        // want to go backwards now 
            // to calculate the postfix 
            // want to immediately take curr of res * postfix --> gets corr ans 
                // res --> is prefix val we got earlier 
        int postfixVal = 1; 
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            res[i] *= postfixVal; 
            postfixVal *= nums[i]; 
        }

        return res; 
    }
};