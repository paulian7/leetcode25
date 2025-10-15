class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // frequency -> hash tables 
        unordered_map<int, int> hashTab; 

        for(int val : nums)
        {
            hashTab[val]++; 
        }

        // bucket sort 
        vector<vector<int>> count(nums.size() + 1);
        for(auto const& pair : hashTab)
        {
            count[pair.second].push_back(pair.first); 
        }

        // return top k 
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