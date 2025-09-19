class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // tech: hash sets -- great for checking for existence --> takes o(1) 

        // time & space comp: 
            // time: o(n) -- just iterating thr each element within array one by one
            // space: o(n) 
                // in the case all elements are unique -> we end up storing n elements in hashSet 

        // 1. declare hash set 
        unordered_set<int> hashSet; 

        // 2. iterate thr array 
        for(int val : nums)
        {
            // check for duplicates first right away 
            if(hashSet.find(val) != hashSet.end())
            {
                // oh no duplicate found! 
                return true; 
            }

            // else, insert to hashSet for later checking 
            hashSet.insert(val); 
        }

        // all checks passed ocne exit out of for-each loop 
        return false; // no duplicates :) 
    }
};