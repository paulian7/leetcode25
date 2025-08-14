class Solution {
public:
    bool isPalindrome(string s) {
        // tech: 
            // 2 pointers 
            // want to compare char at beg && at end at the same time 

        // time & space comp: 
            // time: o(n)
            // space: o(1)
        
        // 1. create our pointers 
        int leftPtr = 0;
        int rightPtr = s.length() - 1;

        // 2. execute 2 pointers method 
        while(leftPtr < rightPtr)
        {
            // ensure all ptrs are @ valid chars
            while(leftPtr < rightPtr && !isalnum(s[leftPtr]))
            {
                leftPtr++;
            }

            while(rightPtr > leftPtr && !isalnum(s[rightPtr]))
            {
                rightPtr--;
            }

            // finally check for equivalence
            if(tolower(s[leftPtr]) != tolower(s[rightPtr]))
            {
                return false;
            }

            // update ptrs for next iteration
            leftPtr++; 
            rightPtr--;
        }
        
        return true;
    }
};