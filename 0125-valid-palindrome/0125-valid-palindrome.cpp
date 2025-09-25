class Solution {
public:
    bool isPalindrome(string s) {
        // ?: what's a palindrome?... read same forwards and backwards
            // want a way to compare both front && back @ the same time 
            // !! --> 2 pointers method
        
        // tech: 2 pointers method 

        // time & space comp: 
            // time: 
            // space: 

        // 1. declare our 2 pointers
        int leftPtr = 0; // start 
        int rightPtr = s.length() - 1; // end

        // 2. start the process 
        while(leftPtr < rightPtr)
        {
            // update pointers FIRST if they're not alphanumeric -- as nonalphanumeric chars are also included here 
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++; 
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--;
            }

            // NOW -- check for == 
                // ensure both chars are lowercased FIRST though before the check
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false; 
            }

            // always ensure pointers are updated before next iteration 
            leftPtr++; 
            rightPtr--;
        }

        // 3. once exit out of while loop, all checks passed --> dealing w/ palindrome :)
        return true;
    }
};