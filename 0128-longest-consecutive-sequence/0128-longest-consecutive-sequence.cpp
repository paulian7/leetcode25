class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // tech: hash sets -- identifying start of seq 

        // time & space comp: 
            // time: o(n)
            // space: o(n)

        // 1. declare hash set & initialize it! 
        unordered_set<int> hashSet(nums.begin(), nums.end()); 

        // 2. declare val to return @ the end
        int longest = 0; 

        // 3. iterate thr hash set -- searching for start of seq 
        for(int val : hashSet)
        {
            if(hashSet.find(val - 1) == hashSet.end())
            {
                // start of a hash set has been found! 
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