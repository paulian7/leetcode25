class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tech: hash map, bucket sort 
            // time comp: o(n)
            // using hash table to count freq of each element 
        
        // 1. declare hash table and count freq of each char 
            // key: val in the given array 
            // value: freq of that specific val
        unordered_map<int, int> count; 
        for(int n : nums)
        {
            count[n]++;
        }

        // 2. create our freq bucket array where indices represent the freq
            // +1 to size of freq vector bc: 
                // the indices of the freq rep the frequencies...
                // .. of the elements that lie within them..
                // so: freq[4] means elements in this bucket appear 4 times 
                // can't just do nums.size() bc freq[4] would go out of bounds
        vector<vector<int>> freq(nums.size() + 1); 
        for(const auto& pair : count) // iterate thr hash table 
        {
            // key: (.first) ==> accesses the element 
            // val: (.second) ==> freq of that element 
                // freq[indexWeWantToAddElementTo].push_back(elementToAdd);
            freq[pair.second].push_back(pair.first); 
        }

        // 3. collect top k freq elements to print out
        vector<int> result;
        for(int i = freq.size() - 1; i > 0; i--)
        {
            // access the elements within that bucket now! 
            for(int n : freq[i])
            {
                result.push_back(n);

                if(result.size() == k)
                {
                    return result;
                }
            }
        }

        return result;
    }
};