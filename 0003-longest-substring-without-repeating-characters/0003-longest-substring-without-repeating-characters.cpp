class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seenChars; 

        int length = 0; 

        // 2 pointers method 
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check for condition 
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                // update our window & remove from hash table 
                seenChars.erase(s[leftPtr]); 
                leftPtr++; 
            }

            seenChars.insert(s[rightPtr]); 

            length = max(length, (rightPtr - leftPtr + 1)); 
        }

        return length;
    }
};