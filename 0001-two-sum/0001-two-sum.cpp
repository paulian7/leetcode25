class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hashing --> want to track value and its index to return 
            // if it was matching w/ other val to add up to target 
        unordered_map<int, int> hashTable; 

        // iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i]; 

            if(hashTable.find(diff) != hashTable.end())
            {
                return {i, hashTable[diff]};
            }

            // insert this val to hash table 
            hashTable[nums[i]] = i;
        }

        return {-1, -1};
    }
};