class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seenChars; 

        int longest = 0;

        int leftPtr = 0;
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check for valid window
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                seenChars.erase(s[leftPtr]); 
                leftPtr++;
            }

            // else, add to hash set 
            seenChars.insert(s[rightPtr]); 
            // update length
            longest = max(longest, (rightPtr - leftPtr + 1));
        }

        return longest;
    }
};