class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: hash tables
        
        // time & space comp: 
            // time comp: o(n + m) 
                // as we're iterating thr 2 strings respectively 
            // space comp: o(1)
                // since we're going thr atmost 26 chars

        // 1. cover base case -- 
            // checking whether or not both strings are the same length 
            // bc if not same length --> can't be anagrams :(
        if(s.length() != t.length())
        {
            return false; 
        }

        // 2. declare and initialize hash tables for each respective string 
        unordered_map<char, int> sTable;
        unordered_map<char, int> tTable;

        // iterate thr the strings to initialize hash table
        for(int i = 0; i < s.length(); i++)
        {
            sTable[s[i]]++;
            tTable[t[i]]++;
        }

        // 3. compare whether or not hash tables are equivalent! 
            // equivalent --> dealing with anagrams! :D 
        return sTable == tTable;
    }
};