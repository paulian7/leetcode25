class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: 
            // way to track freq --> hash tables
            // want to return top k --> sort of bucket sort!

        // time & space comp: 
            // time: o(n)
            // space: 
                // o(n) - n being the num of integers we're storing

        // 1. declare hash table 
        unordered_map<int, int> hashTab;

        // 2. populate hash table 
        for(int val : nums)
        {
            hashTab[val]++;
        }

        // 3. store frequencies in resp buckets
        vector<vector<int>> counts(nums.size() + 1);
        for(auto const& pair : hashTab)
        {
            counts[pair.second].push_back(pair.first);
        }

        // 4. return top k elements now 
        vector<int> res; 
        for(int i = counts.size() - 1; i > 0; i--)
        {
            for(int val : counts[i])
            {
                res.push_back(val);

                if(res.size() == k)
                {
                    return res;
                }
            }
        }

        return res;
    }
};