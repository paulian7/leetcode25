class Solution {
public:
    int characterReplacement(string s, int k) {
        // tech: hashing & sliding window 
            // hashing --
                // want to identify highest freq 
                // can take size of str - highest freq --> to get how many replacements we need 
                // key: char, val: freq of that char 
            // sliding window -- 
                // to track longest substr we can get 
        
        // time & space comp: 
            // time: o(n) - length of str 
            // space: o(m) - dictated by total num of unique chars in string 
        
        // 1. declare final ans to return 
        int longest = 0; 

        // 2. have a helper variable 
            // helps track the highest freq we've seen so far 
            // allows us to have a time comp of o(n) 
            // won't need to always check for highest freq in hash table 
        int maxFreq = 0; 

        // 3. declare hash table 
        unordered_map<char, int> hashCount; 
        
        // 4. FINALLY execute sliding window technique 
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // update hash table trackin' char freqs 
            hashCount[s[rightPtr]]++; 

            // update accordingly if we've found an even higher char freq 
            maxFreq = max(maxFreq, hashCount[s[rightPtr]]); 

            // check if need to update window 
            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                // need to update window! bc num of replac. we need isn't covered by "k" 
                    // num of replac = result from length - maxFreq 
                
                // update freq count in leftPtr in hash table 
                hashCount[s[leftPtr]]--;

                // then update leftPtr itself to shrink window 
                leftPtr++; 
            }

            // update final ans before next iteration 
            longest = max(longest, (rightPtr - leftPtr + 1)); 
        }

        return longest; 
    }
};