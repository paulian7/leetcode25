class Solution {
public:
    bool isPalindrome(string s) {
        // tech: two pointers 
            // let's us compare the front && end of string @ the same time 
        
        // time & space comp: 
            // time: o(n) 
                // as we're iterating from both ends of the string, all elements iterated at most once
            // space: o(1) 
                // no other extra data structures are created, other than the 2 integer vars we declared & initialized
                // would be a diff story if we declared hash tables 
        
        // 1. declare & initialize 2 pointers to respective ends of string 
        int leftPtr = 0; // start of str
        int rightPtr = s.length() - 1; // end of str 

        // 2. start iterating 
        while(leftPtr < rightPtr)
        {
            // update pointers accordingly IF not alphanumeric
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++; // update left to be valid
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--; // update right to be valid
            }

            // check for equivalence now 
                // ensure that chars are LOWERCASED FIRST before checking!
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false; // return false immediately if not == 
            }

            // UPDATE POINTERS FOR NEXT ITERATION
            leftPtr++; 
            rightPtr--;
        }

        // true -- if while-loop finishes execution 
        return true;
    }
};