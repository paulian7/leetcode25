class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // want longest substring w/o duplicate characters 
            // hash sets are handy w/ identifying duplicate characters 
            // inserting elements and removing elements take o(1) time -- very handy 
        
        // want substring -- sliding window technique is handy as we can go thr the string 
            // only tracking characters that are valid to our scenario 
        
        // 1. declare hash set 
        unordered_set<char> seenChars; 

        // track longest substr length -- to return later at the end 
        int longest = 0; 

        // 2. start sliding window technique - by declaring pointers 
        int leftPtr = 0; 

        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            while(seenChars.find(s[rightPtr]) != seenChars.end())
            {
                // fix the window :( 
                
                // take out the val leftPtr 
                seenChars.erase(s[leftPtr]); 
                leftPtr++; 
            }

            // if can't find element.. first time seeing it --> need to add to our hashSet 
                // aka the thing that's actually tracking the validity of our window
            seenChars.insert(s[rightPtr]); 

            longest = max(longest, (rightPtr - leftPtr + 1)); 
        }

        return longest; 
    }
};