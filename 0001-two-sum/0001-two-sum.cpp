class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // tech: hashing / hash tables --> time comp: o(n) 
            // key: val 
            // value: index of that val from the given array 
        unordered_map<int, int> hashTable; 

        // iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i]; 

            if(hashTable.find(diff) != hashTable.end())
            {
                return {i, hashTable[diff]}; 
            }

            hashTable[nums[i]] = i;
        }

        return {}; 
    }
};