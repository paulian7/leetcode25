class Solution {
public:
    int characterReplacement(string s, int k) {
        // tech: hashing & sliding window 
            // "longest substring" --> SLIDING WINDOW
            // "containing same letter" --> us dealing w/ frequency --> hash tables
        
        // time & space comp: 
            // time: o(n) -- iterating thr str 
            // space: o(m) -- num of unique chars stored within our hash table
        
        // 1. declare final ans to return 
        int longest = 0; 

        // 2. have a helper variable 
            // helps track the highest freq we've seen so far 
            // allows us to have a time comp of o(n) 
                // as we're not constantly checking again and again for the highest freq in the table
        int maxFreq = 0; 

        // 3. declare hash table to track freq of each unique val
        unordered_map<char, int> hashCount;

        // 4. FINALLY execute the sliding window technique 
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // update hash table trackin' chars freqs
            hashCount[s[rightPtr]]++; 

            // update maxFreq accordingly if we've found an even larger char freq
            maxFreq = max(hashCount[s[rightPtr]], maxFreq);

            // check if window is needed to be updated
            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                // NEED TO UPDATE WINDOW... 
                    // num of replacements needed... given by --> (rightPtr - leftPtr + 1) - maxFreq 
                    // ... is greater than what's given by "k"

                // update freq count in leftPtr in hash table
                hashCount[s[leftPtr]]--;

                // officially shrink the sliding window thr incrementing leftPtr
                leftPtr++;
            }

            // update final res before next iteration 
            longest = max((rightPtr - leftPtr + 1), longest);
        }

        return longest;
    }
};