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
            // 3. find diff --> let's us iterate once thr the array 
            int diff = target - nums[i]; 

            // 4. search if found in hashTable already 
            if(hashTable.find(diff) != hashTable.end())
            {
                return {i, hashTable[diff]}; 
            }

            // else... add to hash table for later 
            hashTable[nums[i]] = i;
        }

        return {-1, -1}; 
    }
};