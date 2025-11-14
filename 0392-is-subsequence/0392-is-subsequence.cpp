class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPtr = 0; 
        int tPtr = 0; 

        int sLength = s.length(); 
        int tLength = t.length(); 

        while(sPtr < sLength && tPtr < tLength)
        {
            if(s[sPtr] == t[tPtr])
            {
                sPtr++;
            } 

            tPtr++;
        }
        return sPtr == sLength;
    }
};