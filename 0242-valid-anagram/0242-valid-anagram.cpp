class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: 
            // anagrams - hash tables! 
                // hash tables - count freq of chars 
                // if each string has same hash table ....
                // ... then dealing w/ valid anagram pair! 

        // time & space comp: 
            // time: o(n + m) 
                // bc we're iterating thr 2 strings
            // space: o(1) 
                // constant - bc we know we're dealing w/ 26 chars 

        // 1. EDGE CASE CHECK - if same length! 
        if(s.length() != t.length())
        {
            return false; // not an anagram instantly :(
        }

        // 2. create hash tables 
        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT; 

        // 3. populate hash tables 
        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++; 
            hashT[t[i]]++; 
        }

        // 4. return whether or not the 2 hash tables are equivalent 
            // if yes... then we're dealing w/ valid anagrams!
            // valid anagram pairs share the same key-val pairs 
                // aka, each word is made up of the same chars! 
        return hashS == hashT; 

    }
};