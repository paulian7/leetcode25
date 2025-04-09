class Solution {
public:
    string longestPalindrome(string s) {
        // declare and initialize our result string
        string result = "";
        int resultLength = 0;

        // 1. go thr each pos in the string
        for(int i = 0; i < s.length(); i++)
        {
            // dealing w/ ODD LENGTH palindromes ----
            int leftPtr = i;
            int rightPtr = i;

            // starting from the mid then expanding outwards
            while(leftPtr >= 0 && rightPtr < s.length() && s[leftPtr] == s[rightPtr])
            {
                // check if our curr palindrome str is > 
                if((rightPtr - leftPtr + 1) > resultLength)
                {
                    // yes, update our result substr and length
                    result = s.substr(leftPtr, rightPtr - leftPtr + 1); 
                    resultLength = rightPtr - leftPtr + 1;
                }

                // expand our pointers outward - by updating pointers
                leftPtr--;
                rightPtr++;
            }

            // dealing w/ EVEN LENGTH palindromes ----
                // reinitialize our pointers to deal w/ even length palindromes now
            leftPtr = i; 
            rightPtr = i + 1; // bc we have two middle characters (left is one mid char and right is the other)
            while(leftPtr >= 0 && rightPtr < s.length() && s[leftPtr] == s[rightPtr])
            {
                if((rightPtr - leftPtr + 1) > resultLength)
                {
                    result = s.substr(leftPtr, rightPtr - leftPtr + 1); 
                    resultLength = rightPtr - leftPtr + 1;
                }

                // update our pointers 
                leftPtr--;
                rightPtr++;
            }
        }
        
        return result;
    }
};