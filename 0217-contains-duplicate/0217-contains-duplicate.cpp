class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // hash sets --> o(n) 
        unordered_set<int> hashSet;

        // iterate thr our array
        for(int num : nums)
        {
            if(hashSet.find(num) != hashSet.end())
            {
                // a duplicate found!!!! :(
                return true;
            }

            // else, add this new element we've never seen to our array
            hashSet.insert(num);
        }

        return false;
    }
};