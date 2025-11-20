class Solution {
public:
    bool isAnagram(string s, string t) {
        // time: o(n + m) 
        // space: o(1) 

        // edge case 
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