class Solution {
public:
    int characterReplacement(string s, int k) {
        // tech: hash tables & sliding window --> time comp: o(n)

        // 1. declare hash table 
            // key: char of alphabet (26 possible) 
            // val: freq of that char in string 
        unordered_map<char, int> charFreq; 
        int result = 0; 

        // 2. declare 2 pointers 
        int leftPtr = 0; 

        // helper variable 
        int maxFreq = 0; 

        // 3. iterate thr string 
            // rightPtr is our iterator in for-loop 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // incrementing freq for each character 
            charFreq[s[rightPtr]]++; 

            // update maxFreq - helps us determine when to shrink window 
                // taking the maxFreq each time as we'll be...
                // ... taking length of str - maxFreq --> which gives us # of replacements needed 
            maxFreq = max(maxFreq, charFreq[s[rightPtr]]); 

            // update window as necessary 
                // checking if # of allowed replacements cover the needed replacements 
            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                // want to remove the freq of leftPtr's val..
                    // as we're no longer counting that freq 
                charFreq[s[leftPtr]]--; 

                // update leftPtr --> as THIS will move our window AND UPDATE IT
                leftPtr++; 
            }

            // updates result w/ max length of any valid sliding window 
            result = max(result, rightPtr - leftPtr + 1); 
        }

        return result; 
    }
};