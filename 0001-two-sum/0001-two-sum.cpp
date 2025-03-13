class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // tech: hash map 

        unordered_map<int, int> hashTab; 

        // iterate thr the array 
        for(int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i]; 

            // look thr hash table 
            if(hashTab.find(diff) != hashTab.end())
            {
                return {i, hashTab[diff]}; 
            }

            hashTab[nums[i]] = i; 
        }

        return {};
    }
};