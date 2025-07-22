class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // hash sets --> help us write an algo w/ runtime of o(n) 
            // insert, remove, searching for an element --> all o(1) 
        unordered_set<int> hashSet(nums.begin, nums.end()); 

        // var to return @ the end 
        int longest = 0; 

        // iterate thr set checking for start of sequences 
        for(int val : hashSet)
        {
            if(hashSet.find(val - 1) == hashSet.end())
            {
                // start of seq found!! ..... sooooooo
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