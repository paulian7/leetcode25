class Solution {
public:
    int hammingWeight(int n) {
        // tech: modulo operator and shifting bits 

        // time & space comp: o(1) 

        // 1. declare var to return as result 
        int result = 0;

        // 2. iterate thr bits til all relvant bits are gone thr
        while(n > 0)
        {
            // 3. check if our curr bit is a 0 or 1 by using a modulo operator 
                // if 1 --> 1 % 2 = 1 
                // if 0 --> 0 % 2 = 0 
            result += n % 2; 

            // 4. shift bits to the right now
                // to look at next col (aka left from curr) 
            n = n >> 1; 
        }

        return result;
    }
};