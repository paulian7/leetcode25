class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: 
            // hash tables & bucket sort 
        
        // time & space comp: 
            // time: o(n) 
            // space: o(n)
        
        // 1. create and populate our hash table 
            // time: o(n) 
                // iterating thr each val within array and pop hashTab accordnigly 
            // space: o(n) 
                // the vals we're inputting into hash table 
                // could also be all unique 
        unordered_map<int, int> hashCount; 

        for(int i = 0; i < nums.size(); i++)
        {
            hashCount[nums[i]]++; 
        }

        // 2. do bucket sort 
            // index reps a possible freq 
            // time: o(n)
                // iterating thr hash table and pushing appropriate vals to array
            // space: o(n) 
                // bc end of day, still pushing n elements to these buckets overall
        vector<vector<int>> count(nums.size() + 1); 
        for(auto const& pair : hashCount)
        {
            count[pair.second].push_back(pair.first); 
        }

        // 3. want to return top k 
            // time: o(n) --> iterating thr count 
            // space: o(n) 
                // worst case k == n, but usually k < n --> o(n)
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