class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // time: o(n)
        // space: o(n)

        unordered_set<int> hashSet; 
        for(int val : nums)
        {
            // check for existence
            if(hashSet.find(val) != hashSet.end())
            {
                // found a duplicate! 
                return true;
            }

            hashSet.insert(val);
        }

        return false;
    }
};