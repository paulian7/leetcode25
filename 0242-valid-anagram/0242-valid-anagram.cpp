class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: anagram => share same character frequency

        // time & space comp: 
            // time: o(n) 
            // space: o(n)
        
        // 1. deal w/ edge case first! 
        if(s.length() != t.length())
        {
            return false;
        }

        // 2. declare hash tables to track char frequencies 
        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT; 

        // 3. populate hash tables 
        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++; 
            hashT[t[i]]++; 
        }

        // 4. return whether or not all key-value pairs match up 
        return hashS == hashT; 
    }
};