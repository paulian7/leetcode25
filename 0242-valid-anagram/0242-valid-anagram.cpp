class Solution {
public:
    bool isAnagram(string s, string t) {
        // tech: hash tables --> time comp: o(n) 

        // base case 
        if(s.length() != t.length())
        {
            return false; 
        }

        // declare hash tables 
        unordered_map<char, int> hashS; 
        unordered_map<char, int> hashT; 

        // iterate thr both strings 
        for(int i = 0; i < s.length(); i++)
        {
            hashS[s[i]]++; 
            hashT[t[i]]++; 
        }

        return hashS == hashT; 
    }
};