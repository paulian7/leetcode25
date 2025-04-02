class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // tech: hash sets --> time comp: o(n) 

        // 1. declare hash set
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        // 2. iterate thr array
        for (int num : numSet) 
        {
            // check for start of seqs

            // check if we can find the val that came before our curr val
                // if can't... then this if-statement executes
                // which means we found the start of a seq!
            if (numSet.find(num - 1) == numSet.end()) 
            {
                // start counting longest consec seq
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) 
                {
                    length++;
                }

                longest = max(longest, length);
            }
        }
        
        return longest;
    }
};