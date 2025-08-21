class Solution {
public:
    bool isPalindrome(string s) {
        // tech: 
            // palindrome - same forwards & backwards
            // 2 pointers -     
                // allows us to compare front & back
                // @ the same time

        // time & space comp: 
            // time: o(n)
            // space: o(1)
        
        // 1. create our 2 pointers 
        int leftPtr = 0; 
        int rightPtr = s.length() - 1; 

        // 2. start 2 pointers method 
        while(leftPtr < rightPtr)
        {
            // update pointers accordingly 
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++; 
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--;
            }

            // compare for equivalence 
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false;
            }

            // update pointers for next iteration
            leftPtr++; 
            rightPtr--;
        }

        return true; // all checks passed
    }
};