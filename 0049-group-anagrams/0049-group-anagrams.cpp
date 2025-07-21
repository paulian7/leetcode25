class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // time & space complexity: 
            // time:
            // space: 

        // tech: hashing 
            // hash table: key - freq string; val - strings that share that freq str 
        
        // declare our hash table 
        unordered_map<string, vector<string>> hashTab;

        // iterating thr our input array 
        for(int i = 0; i < strs.size(); i++)
        {
            // to track / record freq of each char 
            vector<int> count(26, 0); 
            for(char c : strs[i])
            {
                count[c - 'a']++; 
            }

            // want to build our key to add it to the hash table 
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ","; 
            }

            // finally add to hash table 
            hashTab[key].push_back(strs[i]); 
        }

        // return only the values of the key-val pairs 
        vector<vector<string>> resAnagrams; 
        for(auto const& pair : hashTab)
        {
            resAnagrams.push_back(pair.second); 
        }

        return resAnagrams; 
    }
};