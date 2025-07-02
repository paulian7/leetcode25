class Solution {
public:
    int characterReplacement(string s, int k) {
        // tech: hash tables & sliding window 
            // time comp: o(n) -- 'n' is the length of the string 
            // space comp: o(m) -- 'm' num of unique characters within string 
        
        // 1. declare hash table 
            // key: char (26 possible within alphabet) 
            // val: freq of that char within the string 
        unordered_map<char, int> charFreq; 
        
        // declare var to return as result 
        int result = 0;

        // 2. declare 2 ptrs - for window 
        int leftPtr = 0; 

        // have a helper variable 
            // helps optimize time comp from o(26*n) to o(n) 
            // no need to continuously iterate thr hash table to find highest freq 
        int maxFreq = 0; 

        // 3. iterate thr string 
            // rightPtr iterator here 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // incr freq for each char 
            charFreq[s[rightPtr]]++;

            // update maxFreq accordingly 
                // contians highest freq we've seen so far 
                // the determination of whether or not we shrink the window 
            maxFreq = max(maxFreq, charFreq[s[rightPtr]]); 

            // update window if necessary ---- (if > k)
                // take lengthWindow - maxFreq 
                    // gives num of chars that isn't the char of maxFreq 
                    // aka the num of chars we need to replace 
            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                // need to update window!! 
                // remove freq of leftPtrs val 
                charFreq[s[leftPtr]]--; 

                // update window 
                leftPtr++; 
            }

            // update res accordingly w/ max length if found 
            result = max(result, (rightPtr - leftPtr + 1)); 
        }

        return result;
    }
};