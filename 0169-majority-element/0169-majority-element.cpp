class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // tech: hash table --> time comp: o(n)
            // helps us count element occurences efficiently 
            // key: val --> maps to value: count num of occ of that val 
        
        // 1. declare hash table 
        unordered_map<int, int> numFreq; 

        // 2. iterate thr array 
        for(int val : nums)
        {
            // check if not in hash table first 
            if(numFreq.find(val) == numFreq.end())
            {
                // not yet seen --> add to hash table 
                numFreq[val] = 1; 
            }
            else 
            {
                // val has been seen already --> increment freq (aka val of key-val pair)
                numFreq[val] += 1; 
            }
        }

        // 3. return highest val from the key-val pair 
        for(auto pair : numFreq)
        {
            if(pair.second > nums.size() / 2)
            {
                return pair.first; // return the val w/ the highest majority 
            }
        }

        return 0;
    }
};