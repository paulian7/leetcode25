class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 1. store length of the respective strings 
        int sLength = s.size(); 
        int tLength = t.size(); 

        // 2. declare and initialize pointers 
        int sPtr = 0;
        int tPtr = 0; 

        // 3. iterate thr the strings 
        while(sPtr < sLength && tPtr < tLength)
        {
            // either move both pointers (when we find a match)
            // or move just right ptr (when there is no match)
            if(s[sPtr] == t[tPtr])
            {
                sPtr++; 
            }

            tPtr++; 
        }

        // only true is source string completely iterated thr (which means there's a subsequence) 
        return sPtr == sLength; 
    }
};