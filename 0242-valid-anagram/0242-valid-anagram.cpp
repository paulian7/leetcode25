class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: anagrams! 
            // hash tables! 
                // key: char 
                // val: freq of char 
        
        // time & space comp: 
            // time: o(n + m) 
                // n & m - number of chars dictated by length of strings resp 
            // space: o(1) 
                // 26 possible chars we can store --> simplifies to o(1)
        
        // 1. check edge case 
        if(s.length() != t.length())
        {
            return false;
        }

        // 2. otherwise, create hash tables to compare 
        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT; 

        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++; 
            hashT[t[i]]++;
        }

        // 3. check for equivalency 
            // checks if both hash tables share the same key-val pairs
        return hashS == hashT; 
    }
};