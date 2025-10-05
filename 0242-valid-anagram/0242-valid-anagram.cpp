class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: 
            // anagrams - both strings are made up of the same characters 
            // hash tables perfect to use! 
                // can store key-value pairs for us 
                    // key: characters 
                    // val: freq of that resp character
        
        // time & space comp: 
            // time: o(n + m)
            // space: o(1)
        
        // 1. edge case - checking for length
        if(s.length() != t.length())
        {
            return false;
        }

        // 2. declare hash tables to rep each resp string
        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT;

        // 3. populate hash tables 
        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++; 
            hashT[t[i]]++;
        }

        // 4. compare the 2 hash tables if they're equivalent now
            // yes? -- both are anagrams of one another :)
        return hashS == hashT;
    }
};