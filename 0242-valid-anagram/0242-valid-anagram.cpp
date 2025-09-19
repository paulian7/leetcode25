class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: 
            // checking for anagrams 
                // words that have same char freq as another word
            // hash tables - account for char freq 
        
        // time & space comp: 
            // time: o(n + m) 
                // bc iterating thr 2 strings respectively 
            // space: 
                // o(1) -- due to the fact that our characters we're dealing w/ are limited to the alphabet 
                    // o(26) -> simplifies to o(1)

        // 1. check for length of the 2 strings 
        if(s.length() != t.length())
        {
            return false; // need same length to be anagram :(
        }

        // 2. create hash tables to begin check
        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT; 

        // 3. populate hash tables 
        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++; 
            hashT[t[i]]++;
        }

        // 4. check if both has tables line up 
        return hashS == hashT;
        
    }
};