class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // tech -- hash sets & sliding window 
            // "longest substring" - sliding window 
            // "w/o repeating chars" - hash set 
                // checking for existence - takes o(1) time...
                // ...in comparison to arrays taking o(n)
        
        // time & space comp: 
            // time: o(n) - n, length of str 
                // iterating thr char by char
            // space: o(m) 
                // m - num of unique chars stored in hashSet
        
        // 1. declare final var to return 
        int longest = 0; 

        // 2. declare hash set to track seen chars that are unique 
        unordered_set<char> seenChars; 

        // 3. execute sliding window technique 
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check if we need to shrink the window first 
                // as in, check if we see a repeat w/ this curr char
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                // shrink window until condition no longer holds true

                // remove repeat from hash set
                seenChars.erase(s[leftPtr]); 
                // update leftPtr now to officially shrink the window
                leftPtr++; 
            }

            // IF unique char -- add to hash set for later reference
            seenChars.insert(s[rightPtr]); 

            // update final result now accordingly 
            longest = max((rightPtr - leftPtr + 1), longest);
        }

        return longest;
    }
};