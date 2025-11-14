class Solution {
public:
    int characterReplacement(string s, int k) {
        // tech: substring --> sliding window
            // containing same letter --> dealing w/ freq here --> hash table
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)

        // 1. declare var to return as result 
        int longest = 0;

        // 2. declare hash table to track freq 
        unordered_map<char, int> hashTable;

        // 3. have a variable to track largest freq 
            // helps us do everything in one-pass 
            // don't have to constantly check for largest frequency 
        int maxFreq = 0;

        // 4. iterate thr string now --> establishing sliding window tech
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // populate hash table first 
            hashTable[s[rightPtr]]++;

            // update maxFreq accordingly 
            maxFreq = max(hashTable[s[rightPtr]], maxFreq);

            // check if window update is needed? 
            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                hashTable[s[leftPtr]]--; 

                leftPtr++;
            }

            longest = max(longest, (rightPtr - leftPtr + 1));
        }

        return longest;
    }
};