class Solution {
public:
    int characterReplacement(string s, int k) {
        // tech: hash tables & sliding window --> time comp: o(n) 
            // dealing w/ frequencies --> hash tables!! 

        // 1. declare hash table 
            // key: char of alphabet (26 possible)
            // val: freq of that char within the string 
        unordered_map<char, int> charFreq; 
        int result = 0; 

        // 2. declare our 2 pointers 
        int leftPtr = 0; 

        // have a helper variable -- helps us optimize time comp from o(26*n) -> o(n)
        int maxFreq = 0; 

        // 3. iterate thr string 
            // rightPtr is our iterator in the for-loop 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // incrementing freq for each char 
            charFreq[s[rightPtr]]++; 

            // update maxFreq --> highest freq we've seen 
                // what helps us determine when to shrink window 
                // will later take str.length() - maxFreq 
                    // what gives us # of replacements we need to do
            maxFreq = max(maxFreq, charFreq[s[rightPtr]]); 

            // update window as necessary 
                // checking if # of allowed replacements cover the NEEDED replacements
            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                // want to remove the freq of leftPtr's val 
                    // as we're no longer counting that freq 
                charFreq[s[leftPtr]]--; 

                // update leftPtr --> as this will move our window and update it 
                leftPtr++; 
            }

            // updates res w/ max length of any valid sliding window 
            result = max(result, rightPtr - leftPtr + 1); 
        }

        return result;
    }
};