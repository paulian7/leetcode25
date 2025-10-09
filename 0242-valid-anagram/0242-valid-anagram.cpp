class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: 
            // anagram - sharing same char frequency 
            // frequency --> hash tables
        
        // time & space comp: 
            // time: o(n + m) 
            // space: o(1)
        
        // 1. EDGE CASE - check for same length 
        if(s.length() != t.length())
        {
            return false;
        }

        // 2. build hash tables for each resp string 
        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT; 

        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++; 
            hashT[t[i]]++; 
        }

        // 3. check equivalence of hash tables 
            // if both share same key-val pairs --> dealing w/ anagrams! :) 
        return hashS == hashT; 
    }
};