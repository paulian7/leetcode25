class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // substring --> sliding window technique 
        // without repeating characters? 
            // use hash set for easy reference on whether or not a char has repeated 
        
        // overall time comp: 
        // space comp: 

        unordered_set<char> seenChars; 

        // execute sliding window technique 
        int leftPtr = 0; 

        // final var to return 
        int longest = 0; 

        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check for any repeating characters at first 
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                // val has been seen within our hash set --> a repeat has been found 
                // so we want to update our window!! 

                // remove from hash set first 
                seenChars.erase(s[leftPtr]); 

                // then update our leftPtr to shrink our sliding window 
                leftPtr++; 
            }

            // add to hash set 
            seenChars.insert(s[rightPtr]); 

            longest = max(longest, (rightPtr - leftPtr + 1)); 
        }

        return longest; 
    }
};