class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: hashing 
            // val -> freq of that val 
        
        // time & space comp: 
            // time: 
            // space: 
        
        // 1. declare hash table 
        unordered_map<int, int> hashTab; 

        // 2. iterate thr array 
        for(int val : nums)
        {
            hashTab[val]++; 
        }

        // 3. throw into buckets now 
        vector<vector<int>> count(nums.size() + 1); 
        for(auto const& pair : hashTab)
        {
            count[pair.second].push_back(pair.first);
        }

        // 4. iterate backwards now 
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