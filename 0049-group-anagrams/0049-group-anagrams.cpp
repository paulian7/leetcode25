class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // reason why: 
            // hash tables 
                // key: string freq 
                    // bc want to group all anagrams together in their respective groups 
                // val: strings that match up with this frequency 
            // o(n * m) <-- time comp :(  
        
        //  obv obv - create hash tab 
        unordered_map<string, vector<string>> hashTab; 

        // iterate through array 
        for(int i = 0; i < strs.size(); i++)
        {
            // want to iterate thr each respective string within the array now though :(! 
            vector<int> count(26, 0); 
            for(char c : strs[i])
            {
                // then want a way to track frequencies of char --> to later convert to a string
                    // little ascii trick here 
                    // 'a' - 97 
                    // 'b' - 98 
                    // 98 - 97 = index val of 1 --> increment count at index of 1 
                    // so we know there's currently 1 "b"  
                count[c - 'a']++; 
            }

            // turn this count vector into a string now 
            string key; 
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + ","; 
            }

            // then add this to the hash table 
            hashTab[key].push_back(strs[i]); 
        }

        // finally return our result 
        // want to create another vector for our actual answer 
        vector<vector<string>> resAnagrams; 
        for(auto const& pair : hashTab) 
        {
            resAnagrams.push_back(pair.second); 

            // will push back each group of anagrams 
        }

        return resAnagrams; 
    } 
};