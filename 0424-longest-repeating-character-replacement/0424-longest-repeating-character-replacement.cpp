class Solution {
public:
    int characterReplacement(string s, int k) {
        // want to return the longest SUBSTRING containing the same characters 
            // after k operations (that can help us achieve this goal) 
        
        // overall idea: 
            // need some way to figure out what the majority of our chars are 
            // so we want to count the frequency of each char we come across
            // to associate a char w/ a frequency --> we can use hash tables!! 
            // but, the thing w/ this, is we have to continuously check the hash table again and again for 
                // whatever char has the highest frequency --> time comp: o(26 * n) 
            
            // want longest substring --> sliding window! 
                // helps us track and only track the window (or subarray) that's valid to stated condition 
        unordered_map<char, int> countFreq; 

        // declare 2 pointers 
        int leftPtr = 0; 

        // want to have variable to return at the very end 
        int longest = 0; 

        // let's have a helper variable! that tracks the largest frequency of a char 
            // will actually help optimize our time complexity --> down to o(n) 
        int maxFreq = 0; 

        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // what to populate our hash table 
            countFreq[s[rightPtr]]++; 

            // want to update whether or not we have an ever highest frequency we've come across
            maxFreq = max(maxFreq, countFreq[s[rightPtr]]); 

            // check whether or not we need to update our window 
            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                // want to shrink our window in this case 
                countFreq[s[leftPtr]]--; 

                leftPtr++; 
            }

            // then finally update our final result 
            longest = max(longest, (rightPtr - leftPtr + 1)); 
        }

        return longest; 
    }
};