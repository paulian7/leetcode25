class Solution {
public:
    bool isPalindrome(string s) {
        // palindrome - same forward as backwards 
        // so first and last char == 
        // tech - two pointers method 

        // 1. declare our 2 pointers 
        int leftPtr = 0; 
        int rightPtr = s.length() - 1; 

        // 2. iterate thr our string now 
        while(leftPtr < rightPtr)
        {
            // ensure all pointers are pointing to valid things before actually comparing the two 
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++; 
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--; 
            }

            // finally then check equivalence 
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false; // not a palindrome right off the bat 
            }

            // otherwise, update the pointers once again 
            leftPtr++; 
            rightPtr--;
        }

        return true; // palindroem bc it passed all the checks 
    }
};