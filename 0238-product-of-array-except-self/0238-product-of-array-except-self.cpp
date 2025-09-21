class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // tech: prefix sum 
            // prefix * postfix 
                // one pass forward to get the prefix vals 
                // one pass backwards to get the postfix 
                // can multiply BOTH to get the correct result 
            
        // time & space comp: 
            // time: o(n) 
            // space: 
                // o(n) hash table 
                // o(n * m) -- if output array is countedd
        
        // 1. declare vector to return as result 
        vector<int> answer(nums.size(), 1); 

        // 2. calc the prefix vals first 
            // have prefix val set to 1 to start 
            // ... bc first element doesn't have a prefixVal 
        int prefixVal = 1; 
        for(int i = 0; i < nums.size(); i++)
        {
            // toss prefix into res vector first 
            answer[i] = prefixVal; 

            // actually update our prefix val 
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
                // will get us the product of everything but curr element!! 
            answer[i] *= postfixVal;

            // update postfix val now w/ val in array 
            postfixVal *= nums[i]; 
        }

        return answer; 
    }
};