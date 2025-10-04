class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: want to return MOST FREQUENT ELEMENTS 
            // dealing w/ frequency --> hash tables 
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare hash table 
        unordered_map<int, int> hashTab; 

        // 2. iterate thr array, populating hash table
        for(int val : nums)
        {
            hashTab[val]++;
        }

        // 3. sort into buckets
            // indices represent the freq of that value
        vector<vector<int>> count(nums.size() + 1);
        for(auto const& pair : hashTab)
        {
            count[pair.second].push_back(pair.first); 
        }

        // 4. return top k now 
        vector<int> result;
        for(int i = count.size() - 1; i > 0; i--)
        {
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