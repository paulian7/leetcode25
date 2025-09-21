class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: 
            // hash table - stores key-val pairs
                // key: val; value: freq of that val
            // bucket sort - indices represent freq of the value stored @ that index

        // time & space comp: 
            // time: o(n)
            // space: o(n)

        // 1. declare hash table 
        unordered_map<int, int> hashCount; 
        
        // 2. populate hash table 
        for(int val : nums)
        {
            hashCount[val]++;
        }

        // 3. sort into respective buckets 
        vector<vector<int>> freqCount(nums.size() + 1); 
        for(auto const& pair : hashCount)
        {
            freqCount[pair.second].push_back(pair.first);
        }

        // 4. return top k elements now 
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