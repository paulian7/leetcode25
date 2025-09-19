class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: 
            // anagram - consists of same char freq 
            // hash tables - key: char, val: freq of char 
        
        // time & space comp: 
            // time: o(n + m) -- iterating thr 2 strings
            // space: o(1) -- limited to just 26 distinct chars
        
        // 0. edge case -- check if same length first 
        if(s.length() != t.length())
        {
            return false;
        }

        // 1. create hash tables for each string
        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT; 
        
        // 2. iterate thr chars 
        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++; 
            hashT[t[i]]++; 
        }

        // 3. check for equivalence 
        return hashS == hashT; 
    }
};