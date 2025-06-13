class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // tech: prefix * postfix --> time & space comp: o(n) 
            // one pass forward to get the prefix 
            // one pass backwards for postfix 
            // multiply BOTH together to get the correct result 
        
        // 1. declare vector of size nums
        vector<int> result(nums.size(), 1); // initialize to all default vals of 1

        // 2. calc the prefix vals 
            // have prefix var set to 1 to start bc first element doesn't have prefix val
        int prefixVal = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            // toss prefix into result vector first 
            result[i] = prefixVal; 

            // multiply prefix w/ each element as we go thr the array 
                // as we want culmative product up to that point 
            prefixVal *= nums[i];
        }

        // 3. calc the postfix vals 
        int postfixVal = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            // start multiplying each element w/ our postfix val RIGHT AWAY
                // where we're multiplying both our PRE AND POSTFIX VALS at the same time 
            result[i] *= postfixVal;

            // update postfix w/ val in array 
            postfixVal *= nums[i];
        }

        return result;
    }
};