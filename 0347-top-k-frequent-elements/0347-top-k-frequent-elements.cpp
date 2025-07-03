class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hash tables 
            // helps us track the frequency of a specific element 
        
        // bucket sort 

        unordered_map<int, int> hashTab; 
        for(int num : nums)
        {
            hashTab[num]++; 
        }

        // sort of a bucket sort 
        vector<vector<int>> bucketCounts(nums.size() + 1); 
        for(auto const& pair : hashTab)
        {
            bucketCounts[pair.second].push_back(pair.first); 
        }

        // want to return result 
        vector<int> result; 
        for(int i = bucketCounts.size() - 1; i > 0; i--)
        {
            for(int val : bucketCounts[i])
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