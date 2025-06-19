class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(), nums.end()); 
        int longest = 0; 

        for (int val : hashSet)
        {
            if (hashSet.find(val - 1) == hashSet.end()) // only start if val is start of sequence
            {
                int current = val;
                int length = 1;

                while (hashSet.find(current + 1) != hashSet.end())
                {
                    current += 1;
                    length += 1;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
