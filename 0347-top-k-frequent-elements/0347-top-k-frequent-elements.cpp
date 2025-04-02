class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: hash tables & using bucket sort algo 
            // time comp: o(n) 

        // 1. declare hash table 
            // key: value itself from array 
            // val: freq of that specific val 
        unordered_map<int, int> countTable;
        // populate hash table 
        for(int num : nums) 
        {
            countTable[num]++;
        }

        // 2. create our freq bucket 
            // each index represents a freq 
            // so, want to +1 size of freq array to account for ALL poss freqs w/o going out of bounds 
        vector<vector<int>> freq(nums.size() + 1);
        for(const auto& pair : countTable)
        {
            // pair.second is the index (aka freq), we want to add the val to 
            freq[pair.second].push_back(pair.first);
        }

        // 3. collect top k freq elements to print out now 
        vector<int> result; 
        for(int i = freq.size() - 1; i > 0; i--)
        {
            // access the elements within that bucket now 
            for(int val : freq[i])
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