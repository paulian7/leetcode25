class Solution {
public:
    int characterReplacement(string s, int k) {
        // want to identify the highest frequency --> hash table 
            // key: char
            // val: freq of that resp char 
        // sliding window 
            // to track the longest substr we can get according to the conditions 


        // time comp: 
            // o(n) 
        // space comp: 
            // o(n) 
        
        unordered_map<char, int> hashCount; 

        // final ans to return 
        int longest = 0; 

        // have another helping integer variable 
            // tracks the highest frequency 
        int maxFreq = 0; 

        // sliding window 
        int leftPtr = 0; 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // update our hash table tracking the frequencies 
            hashCount[s[rightPtr]]++; 

            // track to see if we've found the highest freq 
                // helps us reduce the time complexity down 
                // from continuously checking which char has the highest complexity 
            maxFreq = max(maxFreq, hashCount[s[rightPtr]]); 

            // check whether or not we need to update our window 
            while((rightPtr - leftPtr + 1) - maxFreq > k)
            {
                // need to update window bc the number of replacements we do need... isn't covered by k 
                
                // update freq count in leftPtr 
                hashCount[s[leftPtr]]--; 
                
                // then update leftPtr itself to shrink window 
                leftPtr++; 
            }

            // update our final answer 
            longest = max(longest, (rightPtr - leftPtr + 1)); 
        }

        return longest; 
    }
};