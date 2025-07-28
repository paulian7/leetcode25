class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: frequency -> hash tables 
            // key: value 
            // val: freq of that spec value 
            // -- 
            // want to return k most freq elements 
            // bucket sort -- each index within array reps poss freq 
        
        // time & space comp: 
            // time: o(n)
            // space: 
                // hash table: o(n)
        
        // 1. declare hash table 
        unordered_map<int, int> hashCount; 

        // 2. populate the hash table 
        for(int i = 0; i < nums.size(); i++)
        {
            hashCount[nums[i]]++;
        }

        // 3. populate our "bucket sort" array by iterating thr hash table
            // sorting vals into their own buckets based on freq 
            // buckets being "indices" which reps poss freq 
            // doing +1 to the size of the array to cover...
                // all possible frequenceis 
            // also 2d vector bc can have multiple vals share same freq
        vector<vector<int>> count(nums.size() + 1); 
        for(auto const& pair : hashCount)
        {
            count[pair.second].push_back(pair.first); 
        }

        // 4. finally return the top k freq elements by iterating thr 2d vector 
        vector<int> result; 
        for(int i = count.size() - 1; i > 0; i--)
        {
            // want to iterate thr each array now within the 2d vector 
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