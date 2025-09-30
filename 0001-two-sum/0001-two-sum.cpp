class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // tech: want 2 vals that add up to target --> want to also return their indices 
            // want to track 2 corresponding vals @ the same time --> hash tables

        // time & space comp: 
            // time: o(n)
            // space: o(n)

        // 1. declare hash table
        unordered_map<int, int> hashTab; 

        // 2. iterate thr array
        for(int i = 0; i < nums.size(); i++)
        {
            // check for a complement -- what allows us to go thr array in one-pass --> time comp: o(n)
            int diff = target - nums[i]; 

            // check whether or not we've seen this complement 
            if(hashTab.find(diff) != hashTab.end())
            {
                return {i, hashTab[diff]};
            }

            // otherwise, add new key-val pair to hash table 
                // key: value itself 
                // value: index of the corresponding value
            hashTab[nums[i]] = i;
        }

        return {};
    }
};