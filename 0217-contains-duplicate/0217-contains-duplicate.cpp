class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // tech: hash set --> time comp: o(n) 

        unordered_set<int> hashSet; 

        for(const auto& val : nums)
        {
            if(hashSet.find(val) != hashSet.end())
            {
                return true; // dup found 
            }

            // otherwise, add it to hash set as we haven't seen this element yet
            hashSet.insert(val);
        }

        return false;
    }
};