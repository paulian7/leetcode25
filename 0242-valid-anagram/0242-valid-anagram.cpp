class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: 
            // anagrams -- share same char freq 
                // hash tables! - help us track char freq

        // time & space comp: 
            // time: o(n + m)
                // iterating thr both strings, s & t 
            // space: o(1) 
                // constant time, as we're just utilizing pointers

        // 0. check if same length first 
        if(s.length() != t.length())
        {
            return false;
        }

        // 1. declare hash tables
        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT;

        // 2. populate hash tables
        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++;
            hashT[t[i]]++;
        }

        return hashS == hashT;
        
    }
};