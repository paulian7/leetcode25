class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // tech - hash sets & sliding window 
            // "longest substring" - sliding window 
            // "w/o repeating chars" - hash set 
                // as checking for existence of elements is o(1) time 

        // complexity analysis -
            // time: o(n) - n is s.length() 
            // space: o(m) - num of unique characters 

        // 1. declare final var to return 
        int longest = 0; 

        // 2. declare hash set to track seen chars that are unique 
        unordered_set<char> seenChars; 

        // 3. sliding window technique 
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // condition - check for any repeating chars @ first 
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                // need to update window.. repeat has been found! 
                // remove repeat from hash set first 
                seenChars.erase(s[leftPtr]); 

                // update leftPtr to shrink sliding window 
                leftPtr++; 
            }

            // if unique char, add to hash set for later ref 
            seenChars.insert(s[rightPtr]); 

            // update final var to return 
                // (rightPtr - leftPtr + 1) --> gives us curr substring length 
            longest = max(longest, (rightPtr - leftPtr + 1)); 
        }

        return longest; 
    }
};