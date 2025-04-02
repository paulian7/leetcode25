class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // tech: hash tables 

        unordered_map<string, vector<string>> wordFreqs;

        // iterate thr our array 
        for(int i = 0; i < strs.size(); i++)
        {
            vector<int> count(26, 0); 
            // iterate thr each string within the array now 
            for(char c : strs[i])
            {
                // initialize the vals from count appropiately 
                count[c - 'a']++;
            }

            // want to get key from this string now 
            string key; 
            for(int i = 0; i < count.size(); i++)
            {
                key += to_string(count[i]) + ",";
            }

            // actually add this to our hash table now 
            wordFreqs[key].push_back(strs[i]);
        }

        // NOW want to deal w/ actual answer
        vector<vector<string>> ans; 
        for(const auto& pair : wordFreqs)
        {
            ans.push_back(pair.second); 
        }

        return ans;
    }
};