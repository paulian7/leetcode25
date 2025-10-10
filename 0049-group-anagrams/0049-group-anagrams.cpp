class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // tech: 
            // anagrams! - hash tables 
        
        // time & space comp: 
            // time: o(n * m)
            // space: o(n)
        
        // 1. declare hash table 
        unordered_map<string, vector<string>> hashTable; 

        // 2. iterate thr our array 
        for(int i = 0; i < strs.size(); i++)
        {
            // want to iterate thr each char within the string 
                // want a way to track freq of eac char
            vector<int> count(26, 0);
            for(char c : strs[i])
            {
                count[c - 'a']++; 
            }

            // want to convert integer array into a string now 
                // to make it into a key-val pair later
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ","; 
            }

            // finally add to hash table as a new key-val pair 
            hashTable[key].push_back(strs[i]);
        }

        // 3. return just the groups of strings
        vector<vector<string>> resAnagrams;
        for(auto const& pair : hashTable)
        {
            resAnagrams.push_back(pair.second);
        }

        return resAnagrams;
    }
};