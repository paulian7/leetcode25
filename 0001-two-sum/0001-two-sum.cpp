class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // tech: hashing --> let's us do this in one-pass 
        
        // time & space comp: 
            // time: o(n) 
            // space: o(n) 
        
        // 1. declare hash table 
        unordered_map<int, int> hashTab; 

        // 2. iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // check for complement 
            int diff = target - nums[i]; 

            // check for existence of complement 
            if(hashTab.find(diff) != hashTab.end()) 
            {
                // return indices 
                return {i, hashTab[diff]}; 
            }

            // otherwise, insert into hash table as a new pair 
            hashTab[nums[i]] = i;
        }

        return {};
    }
};