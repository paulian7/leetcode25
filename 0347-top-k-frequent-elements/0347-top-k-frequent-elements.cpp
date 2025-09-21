class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: want to count freq 
            // hash tables! 

        // overall time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare hash table 
        unordered_map<int, int> hashTab; 

        // 2. iterate thr array 
            // time: o(n)
            // space: o(n)
        for(int i = 0; i < nums.size(); i++)
        {
            // populate hash table thr each iteration 
            hashTab[nums[i]]++;
        }

        // 3. bucket sort tech 
            // each index represents that value's frequency
            // time: o(n)
            // space: o(n)
        vector<vector<int>> count(nums.size() + 1); 
        for(auto const& pair : hashTab)
        {
            count[pair.second].push_back(pair.first);
        }

        // 4. return top k elements 
            // time: o(n) 
            // space: o(n)
        vector<int> result;
        for(int i = count.size() - 1; i > 0; i--)
        {
            for(int val : count[i])
            {
                result.push_back(val); 

                // check for k size yet? 
                if(result.size() == k)
                {
                    return result;
                }
            }
        }

        return result;
    }
};