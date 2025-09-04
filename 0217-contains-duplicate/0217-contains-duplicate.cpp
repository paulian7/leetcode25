class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // tech: hash sets 

        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare our hash set 
        unordered_set<int> hashSet; 

        // 2. iterate thr given array 
        for(int val : nums)
        {
            // check for duplicates FIRST
            if(hashSet.find(val) != hashSet.end())
            {
                return true; 
            }

            // otherwise, insert unseen val into hash set for later reference 
            hashSet.insert(val); 
        }

        return false;
    }
};