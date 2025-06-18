class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // no sort --> time comp: o(nlogn) 

        unordered_set<int> hashSet(nums.begin(), nums.end()); 
        int longestLength = 0; 

        // iterate thr our given array 
        for(int i = 0; i < nums.size(); i++)
        {
            // track / find somehow the beginning of sequences 
            if(hashSet.find(nums[i] - 1) == hashSet.end())
            {
                // dealing w/ start of seq
                // can actually work on result 
                int length = 1; 
                while(hashSet.find(nums[i] + length) != hashSet.end())
                {
                    length++; 
                }

                longestLength = max(longestLength, length); 
            }
        }

        return longestLength; 
    }
};