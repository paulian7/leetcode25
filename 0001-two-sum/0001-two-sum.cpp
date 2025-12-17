class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // ?: want 2 vals that add up to the target val 

        // tech: hash table 
        
        // time & space comp: 
            // time: o(n) - one-pass -- iterating thr array, searching for 2 vals that add up to target
            // space: o(n) - worst case, store all nums in hash table bc can't find match to target
        
        // 1. declare hash table 
            // key: val, value: index of that val 
        unordered_map<int, int> hashTab; 

        // 2. iterate thr array, one pass only 
        for(int i = 0; i < nums.size(); i++)
        {
            // calc diff - is what allows us to do 1-pass only 
                // makes possible the time comp: o(n) 
            int diff = target - nums[i]; 

            // check if we've seen diff already
            if(hashTab.find(diff) != hashTab.end())
            {
                return {i, hashTab[diff]};
            }

            // otherwise, add new val to hashTab 
            hashTab[nums[i]] = i; 
        }

        // worst case, return nothing 
        return {}; 
    }
};