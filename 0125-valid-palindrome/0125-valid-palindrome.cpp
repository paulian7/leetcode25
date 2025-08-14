class Solution {
public:
    bool isPalindrome(string s) {
        // ?: plaindrome 
            // read same forwards and backwards 
            // want a way to check both ends of the string 
        
        // tech: 2 pointers 
            // each pointer at their own end of the string 
        
        // time & space comp: 
            // time: o(n)
            // space: o(1)
        
        // 1. declare & initialize our pointers 
        int leftPtr = 0; 
        int rightPtr = s.length() - 1; 

        while(leftPtr < rightPtr)
        {
            // want to remove all alphanumeric chars 
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++;
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--;
            }

            // want to lowercase 
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false; // not a palindrome! bc no matches made 
            }

            // want to update our pointers for next iteration 
            leftPtr++; 
            rightPtr--;
        }

        // true --- if all cases are passed!
        return true; 
    }
};