class Solution {
public:
    bool isPalindrome(string s) {
        // ?: palindrome is read same forwards and backwards 
        // tech: 2 pointers from start and end going to middle --> time comp: o(n) 

        // 1. initialize 2 pointers 
        int leftPtr = 0; 
        int rightPtr = s.length() - 1; 

        // 2. iterate thr str w/ left and right ptrs going to middle 
            // check for equivalent --> yes, palindrome! 
        while(leftPtr < rightPtr)
        {
            // account for nonalphabet cases for leftPtr 
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++;
            }

            // account for any nonalphabet cases for rightPtr 
            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--;
            }

            // then check for similarity 
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false;
            }

            // update pointers finally 
            leftPtr++;
            rightPtr--;
        }

        return true;
    }
};