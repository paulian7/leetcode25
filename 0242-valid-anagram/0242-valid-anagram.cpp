class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: 
            // hash tables! 
        
        // time & space comp: 
            // time: o(n + m)
            // space: o(1) -- chars limited to 26 chars
        
        // 1. edge case check
        if(s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT; 

        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++;
            hashT[t[i]]++;
        }

        return hashS == hashT; 
    }
};