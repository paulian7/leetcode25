class Solution {
public:
    int characterReplacement(string s, int k) {
        // tech: 
            // LONGEST && containing same letter substring --> sliding window
            // same letter --> deals w/ freq --> hash tables
        
        // 1. declare result to return @ end 
        int result = 0; 

        // 2. declare hash table 
        unordered_map<char, int> hashTable;

        // 3. declare helper variables 
            // ensures that we don't have to continuously look for the maxFreq 
        int maxFreq = 0;

        // 4. perform sliding window technique 
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check for valid window?? 
            hashTable[s[rightPtr]]++; 
            maxFreq = max(maxFreq, hashTable[s[rightPtr]]);

            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                hashTable[s[leftPtr]]--; 
                leftPtr++;
            }

            result = max(result, (rightPtr - leftPtr + 1));
        }

        return result;
    }
};