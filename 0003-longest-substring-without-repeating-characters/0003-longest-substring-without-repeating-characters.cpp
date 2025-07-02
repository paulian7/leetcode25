class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // longest substring --> sliding window 
        // no repeating characters 
            // easiest way for us is to have a hash set 
            // the hash set basically helps us check for the existence of any duplicates 
                // as this can be done in o(1) constant time 
        
        unordered_set<char> seenChars; 

        int longest = 0; 

        int leftPtr = 0; 

        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check whether or not we found a duplicate 
            // yes dup
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                // oh no dup has been found! -- need to update window 

                // remove leftPtr's whatever value it looked at from hash set 
                seenChars.erase(s[leftPtr]); 

                // update pointer val 
                leftPtr++; 
            }

            // no dup - so need to insert into hash set for later identification of any repeats 
            seenChars.insert(s[rightPtr]); 

            // update max variable 
            longest = max(longest, (rightPtr - leftPtr + 1));
        }

        return longest; 
    }
};