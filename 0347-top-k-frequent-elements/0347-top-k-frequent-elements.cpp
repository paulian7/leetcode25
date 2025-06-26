class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: hash table --> time & space comp: o(n) 
            // key: value 
            // value: freq of that specific value 
        
        unordered_map<int, int> freqTab; 

        // populate this hash table 
        for(int val : nums)
        {
            freqTab[val]++; 
        }

        // throw these frequencies into a bucket 
            // each bucket is an index 
            // indices --> reps a possible frequency 
        vector<vector<int>> freqCounts(nums.size() + 1); 
        for(auto const& pair : freqTab)
        {
            freqCounts[pair.second].push_back(pair.first); 
        }
        
        // then iterate starting from end of bucket array to return result 

        // need variable to return as result 
        vector<int> result; 
        for(int i = freqCounts.size() - 1; i > 0; i--) 
        {
            for(int val : freqCounts[i])
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