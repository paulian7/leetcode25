class Solution {
public:
    bool isPalindrome(string s) {
        // 2 pointers tech --> time comp: o(n) 

        int leftPtr = 0; 
        int rightPtr = s.length() - 1; 

        // execute our 2 pointers method 
        while(leftPtr < rightPtr)
        {
            // account for nonalpha characters 
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++; 
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--; 
            }

            // finally check if it's a palindrome 
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false; 
            }

            leftPtr++; 
            rightPtr--; 
        }

        return true; 
    }
};