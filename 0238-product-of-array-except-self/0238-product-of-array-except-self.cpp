class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // tech: prefix sum 
            // prefix * postfix --> time & space comp: o(n) 
                // one pass forward to get the prefix 
                // one pass backwards to get the postfix 
                // multiply BOTH to get the correct result 
        
        // 1. declare ANS vector of size nums 
        vector<int> result(nums.size(), 1); 

        // 2. calc the prefix vals first 
            // have prefix val set to 1 to start... 
            // ... bc first element element doesn't have a prefix val 
        int prefixVal = 1; 
        for(int i = 0; i < nums.size(); i++)
        {
            // toss prefix into res vector FIRST 
            result[i] = prefixVal; 

            // UPDATE PREFIX VAL - 
                // multiplying prefix w/ each element as we go thr the array 
                // (WHY?) - as we want the culmulative product UP to that point 
            prefixVal *= nums[i]; 
        }

        // 3. calc the POSTFIX vals 
        int postfixVal = 1; 
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            // start multiplying each element w/ our postfix val RIGHT AWAY
                // where we're multiplying both our PRE and POSTFIX vals at the same time 
                // will get us the product of everything but curr element 
            result[i] *= postfixVal; 

            // update postfix val now w/ val in array 
            postfixVal *= nums[i]; 
        }

        return result; 
    }
};