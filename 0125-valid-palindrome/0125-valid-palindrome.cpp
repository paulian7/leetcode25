class Solution {
public:
    bool isPalindrome(string s) {
        // tech: palindrome?? 
            // read same forward and backwards 
            // want a way to compare both ends @ the same time 
            // 2 pointers! 
        
        // time & space comp: 
            // time: o(n)
            // space: o(1)
        
        // 1. declare our 2 pointers 
        int leftPtr = 0; 
        int rightPtr = s.length() - 1;

        // 2. execute 2 pointers method -- iterate thr string --> time comp: o(n)
        while(rightPtr > leftPtr)
        {
            // update pointers accordingly if NOT alphanumeric char
            while(leftPtr < rightPtr && !isalnum(s[leftPtr])) // update left accord. 
            {
                leftPtr++; 
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr])) // update right accord.
            {
                rightPtr--;
            }

            // check for equivalency 
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false;
            }

            // otherwise, update pointers
            leftPtr++;
            rightPtr--;
        }

        return true;
    }
};