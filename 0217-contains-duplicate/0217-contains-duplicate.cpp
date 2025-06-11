class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // tech: hash sets --> time & space comp: o(n) 
            // priority - checking for existence of another element that already exists 
                // aka duplicates 

        // 1. create hash set 
        unordered_set<int> hashSet; 

        // 2. iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // check whether or not this element already exists within the hash set 
            if(hashSet.find(nums[i]) != hashSet.end())
            {
                return true; 
            }

            // else, haven't seen this element yet --> so add to hash set 
            hashSet.insert(nums[i]); 
        }

        // return false as no duplicates were found! 
        return false;
    }
};