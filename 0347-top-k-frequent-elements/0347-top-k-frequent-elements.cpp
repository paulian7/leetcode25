class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: hash tables & using bucket sort algorithm
            // time comp: o(n)
        
        // 1. declare hash table 
            // key: value; value: freq of that val
        unordered_map<int, int> countTable;
        for(int num : nums)
        {
            countTable[num]++;
        }

        // 2. create our freq bucket array 
            // each index represents freq 
            // so, want to +1 size of freq array as freq[4] needs an index 
            // doing just the size of the array itself would make freq[4] go out of bounds
        vector<vector<int>> freq(nums.size() + 1);
        for(const auto& pair : countTable) // iterate thr hash table 
        {
            // pair.second is the index (aka freq) we want to add the val to
            freq[pair.second].push_back(pair.first);
        }

        // 3. collect top k freq elements to print out 
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