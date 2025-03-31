class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // tech: hash set --> time & space comp: o(n) 

        // 1. create hash set 
        unordered_set<int> hashSet; 

        // 2. iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // check whether or not element is already in hash set 
            if(hashSet.find(nums[i]) != hashSet.end())
            {
                return true; // dup found!
            }

            // else, no dup found --> add to hash set for later checkin' 
            hashSet.insert(nums[i]); 
        }

        return false;
    }
};