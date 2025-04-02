class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // time comp: o(n * m) 
            // m - total num of input strings we're given 
            // n - avg length of each of those strings 
        
        // tech - hash table 
            // key - freq of each char in the entirity of a string (separated by commas)
            // val - storing list of strings that share that same freq string
        
        // 1. declare & initialize the hash table 
        unordered_map<string, vector<string>> res; 

        // 2. iterate thr each string from the input array 
        for(const auto& s : strs)
        {
            // declare / initialize an array of 26 0's 
                // each 0 indicating freq of a char 
            vector<int> count(26, 0);

            // initialize the hash table 
                // see an a --> increment count[0] which reps 'a' by 1
            for(char c : s)
            {
                // taking ascii val of curr char subtractin' by 'a' 
                    // will give us correct index! 
                    // to incr the val for 
                count[c - 'a']++;
            }

            // 3. then create key after grabbing freq of each char IN THAT STRING
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ","; 
            }

            // take this key-val pair and add it to our hash table 
            res[key].push_back(s);
        }

        // 4. create vector to specifically return the VALUES now 
            // aka group of anagrams
        vector<vector<string>> resAnagrams;
        for(const auto& pair : res)
        {
            resAnagrams.push_back(pair.second);
        }

        // return our answer! :)
        return resAnagrams;
    }
};