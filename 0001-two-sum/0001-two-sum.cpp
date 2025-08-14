class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // tech: 
            // hash table 
                // want to track 2 vals that assoc. w/ one another
                // key: val 
                // val: index of that val
        
        // 1. declare our hash table 
        unordered_map<int, int> hashTab; 

        // 2. iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // check if we've passed our matching val yet
            int diff = target - nums[i];
            if(hashTab.find(diff) != hashTab.end())
            {
                // return indices! found match! 
                return {i, hashTab[diff]};
            }

            // otherwise, add to hashTab for later
            hashTab[nums[i]] = i;
        }

        return {};
    }
};