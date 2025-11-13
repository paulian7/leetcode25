class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // substring --> sliding window 
        // w/o duplicate chars --> hash set 
            // can only hold unique vals
        
        int longest = 0; 

        unordered_set<char> seenChars; 

        int leftPtr = 0;
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check if window is in need of updating 
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                seenChars.erase(s[leftPtr]);
                leftPtr++;
            }

            seenChars.insert(s[rightPtr]);
            longest = max(longest, (rightPtr - leftPtr + 1));
        }

        return longest;
    }
};