class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // tech: hash tables 
            // lowers brute force (o^2) -> (o(n)) 
            // one pass -> very nice!! 
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare hash table 
        unordered_map<int, int> hashTable; 

        // 2. iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // check for match? -- by first calculating the complement 
                // helps us do problem in one-pass only 
            int diff = target - nums[i];

            // check NOW for a match? 
            if(hashTable.find(diff) != hashTable.end())
            {
                return {i, hashTable[diff]};
            }

            // otherwise, insert key-value pair to hash table for later reference 
                // key: value 
                // value: index of that respective value 
            hashTable[nums[i]] = i;
        }

        return {}; // worst case, return empty array
    }
};