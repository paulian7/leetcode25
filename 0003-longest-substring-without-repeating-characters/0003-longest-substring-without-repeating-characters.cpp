class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // tech: 
            // substring - want longest AND NO duplicate chars --> sliding window
        int longest = 0;
        // 1. declare hash set 
            // can track OUR UNIQUE values
        unordered_set<char> seenChars;

        // 2. set up pointers for our sliding window --> which will track our valid substring
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check if window is valid 
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                seenChars.erase(s[leftPtr]);
                leftPtr++;
            }

            // else... 
            seenChars.insert(s[rightPtr]);
            longest = max(longest, (rightPtr - leftPtr + 1));
        }

        return longest;
    }
};