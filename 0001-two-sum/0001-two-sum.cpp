class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // ?: 2 vals that add up to target val 

        // tech: hash table 
            // allows us to store both val and its index 
            // time comp: o(n), space comp: o(n)

        // 1. declare hash table 
        unordered_map<int, int> hashTab; 

        // 2. iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // 3. calc diff btwn target - currElement 
                // allows us to do 1-pass only --> time comp: o(n) :)) 
            int diff = target - nums[i]; 

            // 4. check if we've seen diff already 
            if(hashTab.find(diff) != hashTab.end())
            {
                return {i, hashTab[diff]};
            }

            // 5. otherwise, add this new curr val to hashTable! 
            hashTab[nums[i]] = i; 
        }

        // 6. worse case - return nothing! 
        return {}; 
    }
};