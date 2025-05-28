class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // tech: hash set --> time comp: o(n) 
            // as we're checking for existence of an element 

        unordered_set<int> hashSet; 

        // iterate thr array checking for any duplicates 
        for(int num : nums)
        {
            if(hashSet.find(num) != hashSet.end())
            {
                // duplicate found!! 
                return true; 
            }

            // otherwise, insert this element we haven't seen yet into hash set 
            hashSet.insert(num); 
        }

        return false; 
    }
};