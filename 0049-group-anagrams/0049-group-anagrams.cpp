class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // tech: group anagrams together? 
            // hash tables! -- key: freq string, val: strings that share same freq string

        // time & space comp: 
            // time: o(n * m)
            // space:
                // o(n) - for the number of strings stored in the hash table created
                // o(n * m) for our output list 
                    // n — num of strings; m — length of longest string 

        // 1. declare hash table 
        unordered_map<string, vector<string>> hashTable;

        // 2. iterate thr array
        for(int i = 0; i < strs.size(); i++)
        {
            // want to iterate thr each char within the curr string now 
            vector<int> count(26, 0); 
            for(char c : strs[i])
            {
                count[c - 'a']++;
            }

            // convert count array into a string to be used as a key 
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ","; 
            }

            // officially add as a key-val pair to hash table
            hashTable[key].push_back(strs[i]);
        }

        // 3. return JUST the grouped anagrams
        vector<vector<string>> resAnagrams;
        for(auto const& pair : hashTable)
        {
            resAnagrams.push_back(pair.second); 
        }

        return resAnagrams;
    }
};