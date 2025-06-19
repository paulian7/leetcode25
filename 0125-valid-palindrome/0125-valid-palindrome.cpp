class Solution {
public:
    bool isPalindrome(string s) {
        // RMBR - PLAINDROME READ SAME FORWARDS AND BACKWARDS 
            // (excluding any spaces & nonalphanumeric characters)
        // tech: 2 pointers from start and end --> then going to middle 
            // time comp: o(n) 

        // 1. initialize 2 pointers 
        int leftPtr = 0; 
        int rightPtr = s.length() - 1; 

        // 2. execute 2 ptrs technique 
            // have left and rightPtrs meet @ the middle 
            // if equivalent --> palindrome! 
        while(leftPtr < rightPtr)
        {
            // check for nonalpha chars w/ LEFTPTR 
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                // then increment for an actual alphanum char 
                leftPtr++; 
            }

            // check for nonalpha chars w/ RIGHTPTR 
            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                // then increment for an actual aphanum char 
                rightPtr--; 
            }

            // FINALLY check for equivalence -- after lowercasing the char 
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false; // not a palindrome immediately 
            }

            // update ptrs for next iteration 
            leftPtr++; 
            rightPtr--; 
        }

        return true; 
    }
};