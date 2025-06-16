class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // anagrams - basically if you scramble the words 
            // you can make the other word 
            // chars should share same frequency 
        
        // tech: hash tables 
            // key: a string that details frequency of each respective character 
            // value: all the strings that share that frequency 
        
        unordered_map<string, vector<string>> hashTab; 

        // 1. iterate thr array 
        for(int i = 0; i < strs.size(); i++)
        {
            // want to iterate through each string now within the overall array 

            // want to also declare a vector 
                // that tracks frequencies of each char 
                // index denotes which char 
                // char 0 --> represents freq count for "a" 
            vector<int> count(26, 0); 
            for(char c : strs[i])
            {
                // using ascii trick here 
                    // 'a' - 'a' --> index 0 --> increment corr index 
                    // that represents freq count tracker for a 
                    // 'b' - 'a' --> 98 - 97 --> 1 --> increment val in index 1 
                count[c - 'a']++; 
            }

            // want to turn that vector of integers into a string to store as a key 
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ","; 
            }

            // add this to the hash table tracker now 
            hashTab[key].push_back(strs[i]); 
        }

        // then actually return our result 
        // want to create yet another vector to help us with this 
        vector<vector<string>> resAnagrams; 
        for(auto const& pair : hashTab)
        {
            resAnagrams.push_back(pair.second); 
        }

        return resAnagrams; // return result! 
    }
};