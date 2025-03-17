class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // time comp: o(m * n) 
            // o(m) - total num of input strings we're given
            // o(n) - avg length of a string (as we're going thr each char in string)
        
        // tech: HASH MAP APPROACH
            // key: stores freq of each char in string separated by a comma 
                // abc --> 1, 1, 1, ......, 0
            // value: stores list of strings that share that freq of each char
        
        // 1. declare and initialize hash table 
        unordered_map<string, vector<string>> res;

        // 2. iterate thr each respective string in the array of strings given 
        for(const auto& s : strs)
        {
            // declare and initialize an array w/ 26 0's (each 0 will be for each char)
            vector<int> count(26, 0);

            // == going thr each char in each string now! 
                // count how much of each char shows up
                // ex: see an a --> increment count[0] (which rep 'a') by 1
            for(char c : s)
            {
                // taking ascii val of curr char we're at and subtracting it by "a" 
                    // ... gives us correct index to increment the value for
                    // ... then we increment that index's value by 1 
                count[c - 'a']++;
            }

            // 3. create our key 
                // add freq of letter "a" to our "key" string first 
            string key = to_string(count[0]);
            // iterate thr count array that contains freq of each char now
            for(int i = 1; i < 26; i++)
            {
                // adds a comma then adds freq of next char in alphabet
                key += ',' + to_string(count[i]);
            }

            // add string to hash table now w/ key-val pair done!
            res[key].push_back(s);
        }

        // 4. create a vector to return our vector of strings of anagrams
        vector<vector<string>> resAnagrams;
        for(const auto& pair : res) 
        {
            resAnagrams.push_back(pair.second);
        }

        return resAnagrams;
    }
};