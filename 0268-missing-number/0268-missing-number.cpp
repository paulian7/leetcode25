class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // tech: hash set --> time comp: o(n)
        unordered_set<int> numSet(nums.begin(), nums.end());

        int expectedMax = nums.size() + 1; 
        for(int num = 0; num < expectedMax; num++)
        {
            if(numSet.find(num) == numSet.end())
            {
                return num; 
            }
        }

        return -1; 
    }
};