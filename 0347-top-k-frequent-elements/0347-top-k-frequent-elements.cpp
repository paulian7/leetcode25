class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hash table 
        unordered_map<int, int> numTable; 

        // populate this table 
        for(int num : nums)
        {
            numTable[num]++; 
        }

        // throw it into buckets (aka a vector)
            // where each index represents a possible freq from the array 
        vector<vector<int>> counts(nums.size() + 1); 
        // populate our vector now :) 
        for(const auto& pair : numTable)
        {
            counts[pair.second].push_back(pair.first); 
        }

        // actually want to return our answer now 
        vector<int> result; 
        for(int i = counts.size() - 1; i > 0; i--)
        {
            for(int num : counts[i])
            {
                result.push_back(num); 

                if(result.size() == k)
                {
                    return result; 
                }
            }
        }

        return result;
    }
};