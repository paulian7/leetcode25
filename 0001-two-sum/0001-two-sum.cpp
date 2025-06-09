class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // tech: hashing --> time comp: o(n) 
            // want to track val and its index to return

        // 1. declare hash table 
        unordered_map<int, int> hashTable; 

        // 2. iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // 3. find diff --> let's us iterate thr the array ONCE 
            int diff = target - nums[i]; 

            // 4. search if found in hashTable already --> o(1) constant time for lookup 
            if(hashTable.find(diff) != hashTable.end())
            {
                return {i, hashTable[diff]}; 
            }

            // else... add to hash table for later lookup 
            hashTable[nums[i]] = i; 
        }

        // worst case return nothing 
        return {}; 
    }
};