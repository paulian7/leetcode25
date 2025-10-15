class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: 
            // dealing w/ frequency of elements --> hash tables
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare hash table 
        unordered_map<int, int> hashTable;

        // 2. populate hash table
        for(int val : nums)
        {
            hashTable[val]++;
        }

        // 3. sort vals into buckets (indices) that rep their correspond freq
        vector<vector<int>> freqCount(nums.size() + 1); 
        for(auto const& pair : hashTable)
        {
            freqCount[pair.second].push_back(pair.first);
        }

        // 4. return top k freq elements 
        vector<int> result;
        for(int i = freqCount.size() - 1; i > 0; i--)
        {
            for(int val : freqCount[i])
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