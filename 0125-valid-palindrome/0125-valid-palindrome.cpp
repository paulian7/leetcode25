class Solution {
public:
    bool isPalindrome(string s) {
        // tech: want to check if same forwards && backwards 
            // 2 pointers technique! -- let's us compare front && back @ the same time 
        
        // time & space comp: 
            // time: 
            // space: 
        
        // 1. declare && initialize our 2 pointers 
        int leftPtr = 0; 
        int rightPtr = s.length() - 1; 

        // 2. start iterating 
        while(leftPtr < rightPtr)
        {
            // update pointers accordingly if NOT an alphanumeric char
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++;
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--;
            }

            // check for equivalence once pointers are valid alphanumerics
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false; // return false immdediately
            }
            
            // update pointers for next iteration 
            leftPtr++; 
            rightPtr--;
        }

        return true; // return true as string passed all checks!
    }
};