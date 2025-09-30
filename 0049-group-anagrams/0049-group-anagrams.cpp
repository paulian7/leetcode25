class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // tech: hash tables 
            // key: string char freq 
            // val: all strings that share this 
        
        // 1. declare our hash table 
        unordered_map<string, vector<string>> hashTable;

        // 2. iterate thr array
        for(int i = 0; i < strs.size(); i++)
        {
            // iterate thr each char within the curr string now 
            // BUT... also want a way to track the freq of each char we're iterating thr
            vector<int> count(26, 0);
            for(char c : strs[i])
            {
                count[c - 'a']++;
            }

            // convert our integer array into a string to use as a key within the hash table
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ",";
            }

            // actually add this into our hash table now! 
            hashTable[key].push_back(strs[i]);
        }

        // 3. return all grouped anagrams we've created
        vector<vector<string>> resAnagrams;
        for(auto const& pair : hashTable)
        {
            resAnagrams.push_back(pair.second);
        } 

        return resAnagrams;
    }
};