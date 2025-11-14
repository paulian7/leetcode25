class Solution {
public:
    bool isPalindrome(string s) {
        // 2 pointers 

        // establish pointers 
        int leftPtr = 0; 
        int rightPtr = s.length() - 1; 

        while(leftPtr < rightPtr)
        {
            // cond 
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++;
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--;
            }

            // actual check
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false;
            }

            // update pointers
            leftPtr++; 
            rightPtr--;
        }

        return true;
        
    }
};