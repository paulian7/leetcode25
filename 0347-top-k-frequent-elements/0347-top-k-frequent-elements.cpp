class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: 
            // hash tables -- use to count freq of each val 
            // bucket sort - to return top k 
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // populate hash table
        unordered_map<int, int> hashCount; 
        for(int i = 0; i < nums.size(); i++)
        {
            hashCount[nums[i]]++;
        }

        // populate bucket sort array
        vector<vector<int>> count(nums.size() + 1);
        for(auto const& pair : hashCount)
        {
            count[pair.second].push_back(pair.first);
        }

        // return top k freq elements now
        vector<int> res; 
        for(int i = count.size() - 1; i > 0; i--)
        {
            for(int val : count[i])
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