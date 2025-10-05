class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // tech: 
            // want to identify if a val appears TWICE 
            // hash sets -- perfect for checking for existence of an element 
                // takes o(1) time to search 
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare hash set 
        unordered_set<int> hashSet; 

        // 2. iterate thr array 
        for(int val : nums)
        {
            // check for any duplicates immediately 
            if(hashSet.find(val) != hashSet.end())
            {
                return true;
            }

            // if not dup, add to hashSet for later reference 
            hashSet.insert(val);
        }

        return false;
    }
};