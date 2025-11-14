class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // tech: 
            // substring --> sliding window
            // want to identify duplicate chars --> hash set 
                // can use to hold only unique characters so far 
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare result to return @ end 
        int result = 0;

        // 2. declare hash set to hold only unique chars
        unordered_set<char> seenChars;

        // 3. execute sliding window technique 
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check if window is still valid
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                // invalid --> we've found a duplicate within our substring
                // need to shrink window w/ leftPtr til window becomes valid again 
                seenChars.erase(s[leftPtr]);
                leftPtr++;
            }

            // else... 
            seenChars.insert(s[rightPtr]);
            result = max(result, (rightPtr - leftPtr + 1));
        }

        return result;
    }
};