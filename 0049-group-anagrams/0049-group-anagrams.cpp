class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hash tables 
            // key: freq string
            // val: all strings that share that freq string 
        
        unordered_map<string, vector<string>> hashTab; 
        for(int i = 0; i < strs.size(); i++)
        {
            // want to iterate thr each char within curr string
            vector<int> count(26, 0); 
            for(int c : strs[i])
            {
                count[c - 'a']++; 
            }

            // want to convert array of indices into a string to actually be a key for hash table 
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ","; 
            }

            // actually add to hash table now 
            hashTab[key].push_back(strs[i]); 
        }

        // now want to return our actual result 
        vector<vector<string>> resAnagrams; 
        for(auto const& pair : hashTab)
        {
            resAnagrams.push_back(pair.second); 
        }

        return resAnagrams;
    }
};