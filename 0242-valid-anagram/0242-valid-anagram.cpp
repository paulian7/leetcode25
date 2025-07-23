class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: 
            // anagrams - same char freq 
        
        if(s.length() != t.length())
        {
            return false; 
        }

        // 1. create hash tables 
        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT; 

        // 2. populate the tables 
        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++;
            hashT[t[i]]++; 
        }

        return hashS == hashT; 
    }
};