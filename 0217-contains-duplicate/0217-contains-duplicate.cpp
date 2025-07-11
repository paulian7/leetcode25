class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // hash sets -- 
            // time comp - o(n) 
            // space comp - o(n)
            
        unordered_set<int> hashSet; 

        // iterate thr our given array
        for(int val : nums)
        {
            // check for any duplicates 
            if(hashSet.find(val) != hashSet.end())
            {
                // duplicate found! 
                return true; 
            }

            // otherwise, insert new element into hash set 
            hashSet.insert(val); 
        }

        return false; 
    }
};