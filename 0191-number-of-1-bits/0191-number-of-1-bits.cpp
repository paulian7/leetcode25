class Solution {
public:
    int hammingWeight(int n) {
        // TIME COMPLEXITY: o(1) --> constant time 
        
        // 1. declare and initialize variable to return as result 
        int result = 0; 

        while(n > 0)
        {
            // check if our curr column is a 0 or 1 --> use modulo operator (%)
                // if dealing w/ a 1 --> 1 % 2 --> will give us a 1 --> add it to our result! 
                // deal w/ a 0 --> 0 % 2 --> just give us a 0 
            result += n % 2;  

            // look at next column to the left now by shifting everything to the right by 1
            n = n >> 1; 
        }

        return result; 
    }
};