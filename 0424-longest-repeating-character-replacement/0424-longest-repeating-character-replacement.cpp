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
        
        // var to return as result 
        int maxFreq = 0;

        // rightPtr declared in for-loop as we iterate thr string
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // incrementing freq (the value) for each key
            charFreq[s[rightPtr]]++;

            // update maxFreq 
                // taking the maxFreq each time as we'll be...
                // taking length of str - maxFreq --> which gives us # of replac...
                // ...we need to do 
            maxFreq = max(maxFreq, charFreq[s[rightPtr]]);

            // update window if necessary 
                // checking if # of allowed replacements cover the needed replacements
            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                // want to remove the freq of that value leftPtr pointed to from hash table
                    // as we're no longer counting that freq
                charFreq[s[leftPtr]]--;

                // update leftPtr --> move the window along 
                leftPtr++;
            }

            // updates result w/ max length of any valid sliding window
            result = max(result, rightPtr - leftPtr + 1);
        }

        return result;
    }
};