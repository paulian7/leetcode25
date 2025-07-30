class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // tech: hash tables 
            // key: frequency string
            // value: all the strings that share that freq string 

        // time & space comp: 
            // time: o(n * m) 
                // n - number of strings
                // m - length of longest string 
            // space: 
                // o(n) for the strings stored in the hash table 
                // o(n * m) for our output list
        
        // 1. declare hash table 
        unordered_map<string, vector<string>> anaTable; 

        // 2. iterate thr each string 
        for(int i = 0; i < strs.size(); i++)
        {
            // iterate thr each char now within THAT string

            // need a way to track freq of each char 
                    // have vector
                    // where each index represents a poss freq 
                    // use ascii trick
                        // take curr char - 'a' --> gives correct index to increment +1 to track freq
            vector<int> count(26, 0); 
            for(char c : strs[i])
            {
                count[c - 'a']++; 
            }

            // convert "count" integer array into a string type 
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ","; 
            }

            // add new KEY to hash table w/ corresponding val 
            anaTable[key].push_back(strs[i]);
        }

        // 3. return the values of each key-val pair from hash table 

        // first declare vector to return as result 
        vector<vector<string>> result; 
        for(auto const& pair : anaTable)
        {
            result.push_back(pair.second); 
        }

        return result; 
    }
};