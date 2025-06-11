class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tracking the freq of each val 
            // hash table - key-val pairs 
                // key: actual value itself 
                // value: frequency of that specific value 
        unordered_map<int, int> hashTab; 

        // populate this table by iterating thr our input array 
        for(int val : nums)
        {
            hashTab[val]++; 
        }

        // throw all values into a vector 
            // where each index represents frequency 
        vector<vector<int>> count(nums.size() + 1); 
        for(auto const& pair : hashTab)
        {
            count[pair.second].push_back(pair.first); 
        }

        // want to return k most frequent elements 
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