class Solution {
public:
    bool isPalindrome(string s) {
        // tech: need to read same forwards && backwards 
            // need a way to track both the start and end of string @ the same time 
            // 2 pointers method! 
        
        // time & space comp: 
            // time: o(n) ?? 
            // space: o(1) 

        // 1. declare our 2 pointers to start w/ 
        int leftPtr = 0; 
        int rightPtr = s.length() - 1;

        // 2. start executing 2 pointers method 
        while(leftPtr < rightPtr)
        {
            // update pointers accordingly before equivalence check
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++; 
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--; 
            }

            // equivalence check! 
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false;
            }

            // else, prepare pointers for next iteration 
            leftPtr++; 
            rightPtr--; 
        }

        // 3. if while-loop finishes --> all checks passed --> valid palindrome! 
        return true;
    }
};