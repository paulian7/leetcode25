class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // ?: want to have a result array 
            // where the curr element is the product of everything but itself
        
        // tech: 
            // bc we are calculating a lot of products --> can use prefix sums tech
        // time & space comp: 
            // time: o(n)
            // space: o(n), o(1)
        
        // 1. declare our result array to return 
        vector<int> answer(nums.size(), 1); 

        // 2. execute our prefix vals
            // prefixVals * postfixVals = result we want
        int prefixVal = 1; 
        for(int i = 0; i < nums.size(); i++)
        {
            answer[i] = prefixVal;

            prefixVal *= nums[i];
        }

        // 3. execute our postfix vals 
            // immediately multiplying it w/ ans[i] as we want prod of everything except...
        int postfixVal = 1; 
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            answer[i] *= postfixVal; 

            postfixVal *= nums[i]; 
        }

        return answer; 
    }
};