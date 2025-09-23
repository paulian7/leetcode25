class Solution {
public:
    bool isPalindrome(string s) {
        // tech: 
            // palindrome - read same forwards and backwards
            // 2 pointers method! 
                // can compare start && end of string @ the same time 
            
        // time & space comp: 
            // time: o(n) 
                // going thr each char once -- no repeats
            // space: o(1) 
                // as we're just using pointers -- integer variables (nothing in comparison to hash table declarations)
        
        // 1. declare & initialize 2 pointers 
        int leftPtr = 0; 
        int rightPtr = s.length() - 1;

        // 2. start 2 ptrs method 
        while(leftPtr < rightPtr)
        {
            // update pointers accordingly until equivalence check! 
            while(!isalnum(s[leftPtr]) && leftPtr < rightPtr)
            {
                leftPtr++; 
            }

            while(!isalnum(s[rightPtr]) && rightPtr > leftPtr)
            {
                rightPtr--; 
            }

            // NOW - check for equivalence
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false; // not palindrome, return false right away
            }

            // otherwise, if all pass, update pointers for next iteration
            leftPtr++; 
            rightPtr--;
        }

        // 3. if while-loop finishes - palindrome is true :)
        return true;
    }
};