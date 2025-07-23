class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // tech: hash sets 
            // check for dups 
            // insertion & searching for existence of element takes o(1) time 
        
        // time & space comp:
            // time: o(n)
            // space: o(n)

        // 1. create hash set 
        unordered_set<int> hashSet; 

        // 2. iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // check whether or not this element already exists within the hash set 
            if(hashSet.find(nums[i]) != hashSet.end())
            {
                return true; // true -- as a dup has been found!
            }

            // else, haven't seen this element yet --> so add to hash set 
            hashSet.insert(nums[i]); 
        }

        // return false as no duplicates were found! 
        return false;
    }
};