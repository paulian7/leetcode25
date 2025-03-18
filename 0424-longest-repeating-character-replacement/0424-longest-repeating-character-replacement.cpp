class Solution {
public:
    int characterReplacement(string s, int k) {
        // time comp: o(n)
            // brute force: o(n^2).. checking every single substr
        // approach: HASH MAP and SLIDING WINDOW
            // count num of occurences of each char
            // length of window - count of most freq char
            // = which gives us num of chars in our window that we need to replace to match our most freq char

            // 1. declare our hash map being used 
                // key: character of the alphabet (26 possible)
                // val: freq of that character in str
            unordered_map<char, int> charFrequencies; 
            int result = 0;

            // 2. declare / initialize our left and right ptrs for sliding window 
            int leftPtr = 0; 

            // declare maxFreq as well
            int maxFreq = 0;

            // rightPtr declared / initialized in for-loop
            for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
            {
                // incres freq of chars accordingly in hash map 
                charFrequencies[s[rightPtr]]++; 

                // initialize maxFreq
                    // gets most common freq in curr window
                maxFreq = max(maxFreq, charFrequencies[s[rightPtr]]);

                // sliding window! - ensure curr window is valid 
                    // rightPtr - leftPtr + 1: gets length of str 
                        // +1 ensures we get all elements in the range (including the ptrs)
                while((rightPtr - leftPtr + 1) - maxFreq > k)
                {
                    // condition isn't valid :(... so need to update our leftPtr...
                        // and subsequently our sliding window 
                    charFrequencies[s[leftPtr]]--; // remove freq of char by 1 in hash map 
                    leftPtr++; // incr leftPtr --> updates hash map
                }

                // updates result w/ max length of any valid sliding window 
                result = max(result, rightPtr - leftPtr + 1); 
            }

            return result;
    }
};