class Solution {
public:
    int hammingWeight(int n) {
        // tech: modulo operator & shifting bits 

        // time & space comp: o(1) 

        // 1. declare result var to return 
        int result = 0; 

        // 2. iterate thr the bit representation of 'n' til no more relvant bits to 'n'
        while(n > 0)
        {
            // mod operator curr bit to add +1 to result if we're curr at a 1
            result += n % 2; 

            // shift to next bit to look @ 
            n = n >> 1; 
        }

        return result;
    }
};