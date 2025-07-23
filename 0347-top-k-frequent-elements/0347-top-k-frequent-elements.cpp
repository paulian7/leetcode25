class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // the most frequent elements 
            // hash tables - helpful in tracking freq 
                // key: val 
                // val: freq of that val
        // return most freq 
            // can do a bucket sort where each index reps a possible freq
        

        // time & space comp: 
            // time: o(n) 
            // space: o(m)
        
        // 1. declare our hash table 
        unordered_map<int, int> hashCount; 

        for(int val : nums)
        {
            hashCount[val]++; 
        }

        // 2. bucket sort 
        vector<vector<int>> count(nums.size() + 1); 
        for(auto const& pair : hashCount)
        {
            count[pair.second].push_back(pair.first); 
        }

        // 3. want to return our result 
        vector<int> result; 
        for(int i = count.size() - 1; i > 0; i--)
        {
            // want to iterate thr each val now 
            for(int val : count[i])
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