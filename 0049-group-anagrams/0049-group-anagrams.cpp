class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // tech - hash table 
            // key - freq of each char in str (separated by commas) 
            // val - storing list of strings that share that same freq string 
        
        // 1. declare & initialize the hash table 
        unordered_map<string, vector<string>> res; 

        // 2. iterate thr EACH STRING from the input array 
        for(const auto& s : strs)
        {
            // 3. declare / initialize an array of TWENTY-SIX 0's 
                // each 0 indicating freq of a char 
            vector<int> count(26, 0); 

            // 4. initialize the hash table 
                // see an a --> increment count[0] which reps 'a' by 1 
            for(char c : s) 
            {
                // taking ascii val of curr char and subtracting it by 'a' 
                    // helps us give correct index to incr val for 
                    // ex: 'c' - 'a' --> 99 ascii val - 97 ascii val --> gives index 2 
                count[c - 'a']++; 
            }

            // 5. then create key after grabbing freq of char in THIS STRING 
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ","; 
            }

            // 6. take this key-val pair and add it to our hash table 
            res[key].push_back(s); 
        }

        // 7. after iterating thr all strings in input array....
            // create vector to specifically return our RESULT! :D 
        vector<vector<string>> resAnagrams;
        for(const auto& pair : res)
        {
            resAnagrams.push_back(pair.second); 
        }

        // 8. finally return our answer :) 
        return resAnagrams;
    }
};