class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // time comp: o(n * m) 
            // m - total num of input strings we're given 
            // n - avg length of each of those strings 
        
        // tech - hash table 
            // key - freq of each char in string separated by comma 
            // val - stores list of strings that share the same freq of char's 
        
        // 1. declare and initialize hash table 
        unordered_map<string, vector<string>> res; 

        // 2. iterate thr each string from the input array
        for(const auto& s : strs) 
        {
            // declare / initialize array of 26 0's 
                // each 0 indicaing freq of a char 
            vector<int> count(26, 0);

            // iniitializing the hash table 
                // see an a --> increment count[0] which reps 'a' by 1
            for(char c : s)
            {
                    // taking ascii val of curr char subtrac. by 'a'
                        // will give us correct index...
                        // to incr. the value for 
                count[c - 'a']++;
            }

            // 3. then create key after grabbing freqs of each char 
            string key;
            for(int i = 0; i < 26; i++) {
                key += to_string(count[i]) + ",";  // Ensures separation
            }

            res[key].push_back(s);
        }

        // 4. create vector to return everything now :)
            // want specifically the values 
        vector<vector<string>> resAnagrams;
        for(const auto& pair : res)
        {
            resAnagrams.push_back(pair.second);
        }

        return resAnagrams;
    }
};