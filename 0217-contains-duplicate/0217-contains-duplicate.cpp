class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // time & space comp: 
            // time: o(n) 
            // space: o(n) 

        unordered_set<int> seenChars; 

        for(int val : nums)
        {
            if(seenChars.find(val) != seenChars.end())
            {
                return true;
            }

            seenChars.insert(val);
        }

        return false;
    }
};