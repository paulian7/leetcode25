class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: hash tables + bucket sort 
            // time comp: o(n)
            // space comp: o(n) 
                // worst case - all values are unique 
        
        // 1. declare hash table 
            // key: reps value from array 
            // val: freq of that spec value 
        unordered_map<int, int> numTable; 

        // 2. iterate thr input array to populate hashTable
        for(int num : nums)
        {
            numTable[num]++; 
        }

        // 3. throw each of the vals into buckets 
            // (aka each bucket being an element of a vector)
            // each index representing a poss freq from the array 
        vector<vector<int>> counts(nums.size() + 1); 
        for(const auto& pair : numTable)
        {
            counts[pair.second].push_back(pair.first); 
        }

        // 4. return top k most frequent elements now by iterating thr 2d vector 
        vector<int> res; 
        for(int i = counts.size() - 1; i > 0; i--)
        {
            for(int num : counts[i])
            {
                res.push_back(num); 

                // check if we've reached top k 
                if(res.size() == k)
                {
                    return res;
                }
            }
        }

        return res; 
    }
};