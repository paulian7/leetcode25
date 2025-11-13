class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // tech: hash sets 
            // want to identify elements 
            // can identify elements in (1) time in comparison to linear search in arrays
        
        // time & space comp: 
            // time: o(n) 
            // space: o(n)

        // 0. declare var to return as result
        int longest = 0;
        
        // 1. declare hash set 
        unordered_set<int> hashSet(nums.begin(), nums.end());

        // 2. iterate thr array 
        for(int val : nums)
        {
            // identify starts of sequences 
            if(hashSet.find(val - 1) == hashSet.end())
            {
                int length = 1; 
                while(hashSet.find(val + length) != hashSet.end())
                {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
        

    }
};