class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // tech: 
            // hashing -- hash table (freq string->strs that share it)

        // time & space comp: 
            // time: o(n * m)
            // space: o(n) -- 'n' being num of strings stored into hash table
        
        // 1. declare hash table 
        unordered_map<string, vector<string>> hashTab;

        // 2. iterate thr string 
        for(int i = 0; i < strs.size(); i++)
        {
            // iterate thr each char in each element str
            vector<int> count(26, 0); // have way to track char freqs
            for(char c : strs[i])
            {
                // utilize an ascii trick here 
                    // curr - 'a' --> gives corr index to increment 
                count[c - 'a']++; 
            }

            // convert "count" array to a string to use as our "key" for hash table
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ","; 
            }

            // add key-val pair to hash table 
            hashTab[key].push_back(strs[i]);
        }

        // 3. return only the pair.second now 
        vector<vector<string>> resAnagrams;
        for(auto const& pair : hashTab)
        {
            resAnagrams.push_back(pair.second); 
        }

        return resAnagrams;
    }
};