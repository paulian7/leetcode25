class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // tech: 
            // want to group anagrams together w/ one another 
                // hash tables! 
        
        // time & space comp: 
            // time: o(n * m) 
                // n - number of strings we're iterating thr
                // m - avg length of a string we're iterating thr
            // space: 
                // o(n * m) - IF we count the 2d output vector
                // o(n) - otherwise, is o(n) for the num of strings we're inputting into hash table
        
        // 1. declare hash table
        unordered_map<string, vector<string>> hashTable;

        for(int i = 0; i < strs.size(); i++)
        {
            // iterate thr each char now 
            // but, we want a way to count each char... so array! 
            vector<int> count(26, 0); // dealing w/ 26 poss letters
            for(char c : strs[i])
            {
                // using ascii trick here 
                // 'a' - 'a' --> gives val of 0 
                    // want to increment val of 0 (which reps letter 'a') by 1! 
                count[c - 'a']++;
            }

            // convert count array into an actual string to be stored into hashTab
            string key;
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ",";
            }

            // finally add to hash table
            hashTable[key].push_back(strs[i]);
        }

        // 2. return ans 
        vector<vector<string>> resAnagrams;
        for(auto const& pair : hashTable)
        {
            resAnagrams.push_back(pair.second);
        }

        return resAnagrams;
    }
};