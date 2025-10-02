class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: return k most frequent elements 
            // dealing w/ frequency --> hash tables! 
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)

        // 1. declare hash table 
        unordered_map<int, int> hashTable; 

        // 2. iterate thr array, populating hashTable 
        for(int val : nums)
        {
            hashTable[val]++; 
        }

        // 3. sort numbers into their appropriate frequency bucket 
            // "freq bucket" - being the index 
        vector<vector<int>> count(nums.size() + 1); 
        for(auto const& pair : hashTable)
        {
            count[pair.second].push_back(pair.first); 
        }

        // 4. return top k freq elements now 
        vector<int> result; 
        for(int i = count.size() - 1; i > 0; i--)
        {
            // ensure you're iterating thr each val within each bucket 
            for(int val : count[i])
            {
                result.push_back(val); 
                if(result.size() == k)
                {
                    return result;
                }
            }
        }

        return result;
    }
};