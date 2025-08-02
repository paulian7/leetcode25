class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // tech: 
            // sliding window -- 
                // "longest substring"
            // hash sets --
                // want to identify any dup chars 
                // checking for existence takes o(1) time
                // insertion o(1) time :)
        
        // time & space comp: 
            // time: 
            // space: o(m) 
                // m - being the number of unique chars we've come across
        
        // 1. declare var to return at the end 
        int result = 0; 

        // 2. declare hash set to track seenChars
        unordered_set<char> seenChars;

        // 3. execute sliding window tech
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check immediately for any repeats
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                // we've come across a duplicate :(
                
                // (1) remove the dup from hash set 
                    // our hash set tracks the unique chars we've found
                seenChars.erase(s[leftPtr]);

                // (2) update leftPtr now 
                    // leftPtr - is what shrinks the window 
                    // rightPtr - is what helps us grow the window
                leftPtr++;
            }

            // otherwise, insert this UNSEEN char to our hash set for later
            seenChars.insert(s[rightPtr]); 

            // update var to return at end 
            result = max(result, (rightPtr - leftPtr + 1));
        }

        return result;
    }
};