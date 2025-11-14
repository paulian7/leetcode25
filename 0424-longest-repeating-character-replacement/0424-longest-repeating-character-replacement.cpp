class Solution {
public:
    int characterReplacement(string s, int k) {
        // tech: substring --> sliding window
            // longest repeating --> frequency -> hash tables
        
        // time & space comp: 
            // time: 
            // space: 
        
        // 1. declare hash table 
        unordered_map<char, int> hashCount; 

        // 2. declare variables to help us && result variable
        int longest = 0; 

        int maxFreq = 0; 

        // 3. start sliding window technique 
        int leftPtr = 0;
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // populate the table 
            hashCount[s[rightPtr]]++;

            // poss check if this char is the maxFreq right now
            maxFreq = max(maxFreq, hashCount[s[rightPtr]]);

            // check if sliding window is still valid
            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                hashCount[s[leftPtr]]--; 
                leftPtr++;
            }

            // update length otherwise 
            longest = max(longest, (rightPtr - leftPtr + 1));
        }

        return longest;
    }
};