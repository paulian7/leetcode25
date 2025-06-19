class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix sums --> time comp: o(n)

        // 1. iterate left -> right 
            // calculation of prefix products 
            // culumative product up to our current element 
        
        // want to declare our array to return 
        vector<int> resArray(nums.size(), 1); 

        int prefixVal = 1; 
        for(int i = 0; i < nums.size(); i++)
        {
            resArray[i] = prefixVal; 
            prefixVal *= nums[i]; 
        }

        // 2. iterate right -> left 
            // calculations of postfix products 
            // immediately multiplying post times prefix 
            // which will get us the product of array except self that we want 

        int postfixVal = 1; 
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            resArray[i] *= postfixVal; 
            postfixVal *= nums[i]; 
        }

        return resArray; 
    }
};