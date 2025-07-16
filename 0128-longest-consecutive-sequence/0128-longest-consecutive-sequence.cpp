class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ?: find longest consec seq w/o sorting the array 
            // sorting the array takes o(n logn time)
            // we want o(n) time 
        
        // tech: hash sets 
            // iterating thr array --> o(n) time 
            // lookups for existence of a val --> o(1) time 
        
        // time & space comp: 
            // time: o(n) 
            // space comp: o(n) 
        
        // 1. declare variable to return as result variable 
        int longest = 0; 

        // 2. declare hash set 
        unordered_set<int> hashSet(nums.begin(), nums.end()); 

        // 3. iterate thr array searching for longest consec seq 
        for(int val : hashSet)
        {
            // check if we found the start of a sequence 
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