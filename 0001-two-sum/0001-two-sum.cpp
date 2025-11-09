class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // tech: hash tables 
            // can track 2 things that correlate w/ one another @ the same time 
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare hash table
        unordered_map<int, int> hashTable; 

        // 2. iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // check for any matching pairs.. by finding difference 
            int diff = target - nums[i]; 
            if(hashTable.find(diff) != hashTable.end())
            {
                return {i, hashTable[diff]};
            }

            // else, add new key-val pair to hash table for later reference
            hashTable[nums[i]] = i;
        }

        return {};
    }
};