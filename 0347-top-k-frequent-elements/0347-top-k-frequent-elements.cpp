class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // want a way to count the frequency of these elements 
        unordered_map<int, int> hashCount; 

        for(int val : nums)
        {
            hashCount[val]++; 
        }

        // want to throw this into buckets 
            // each index will represent a possible frequency 
        vector<vector<int>> counts(nums.size() + 1); 
        for(auto const& pair : hashCount)
        {
            counts[pair.second].push_back(pair.first); 
        }

        // want to actually return our result 
        vector<int> result; 
        for(int i = counts.size() - 1; i > 0; i--)
        {
            for(int val : counts[i])
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