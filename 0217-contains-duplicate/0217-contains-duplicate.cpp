class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // tech: detecting duplicates 
            // hash sets! --> checking for existence takes o(1) time 
        
        // time & space comp:  
            // time: o(n)
            // space: o(n)
        
        // 1. declare hash set 
            // acts as a reference -- holds UNIQUE values we've seen so far
        unordered_set<int> seenVals;

        // 2. iterate thr array 
        for(int val : nums)
        {
            // check immediately first if we see a duplicate?? 
            if(seenVals.find(val) != seenVals.end())
            {
                // if-condition true? --> duplicate has been found! 
                return true;
            }

            // else, no duplicate?? add unique val to hashSet for later reference 
            seenVals.insert(val); 
        }

        // 3. return true once we've iterated thr entire array w/o any dups detected
        return false;
    }
};