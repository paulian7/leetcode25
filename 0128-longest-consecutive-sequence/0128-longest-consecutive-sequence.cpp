class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // tech: 
            // unsorted 
            // identify starts of a seq --> then count up from there 
            // identifying elements --> hash sets 

        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare result to return 
        int result = 0; 

        // 2. declare set 
            // can use to advantage --> finding elements take o(1) time 
                // unlike w/ arrays where searching takes o(n) time
        unordered_set<int> hashSet(nums.begin(), nums.end());

        // 3. iterate thr hash set now instead for easy lookups 
        for(int val : hashSet)
        {
            // check for start of sequences
            if(hashSet.find(val - 1) == hashSet.end())
            {
                // found start of sequence
                int length = 1; 
                while(hashSet.find(val + length) != hashSet.end())
                {
                    length++;
                }

                result = max(result, length);
            }
        }

        return result;
    }
};