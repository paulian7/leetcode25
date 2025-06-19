class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // tech: hash sets & sliding window 
            // time comp: o(n) --> length of input string 
            // space comp: o(m) --> total num of unique chars 
        
        // ?: want longest subarray w/ no duplicates 
            // want to use sets as they don't allow duplicates 
        
        // 1. declare a set 
        unordered_set<char> charsVisited; 

        // 2. declare / initialize our 2 pointers for SLIDING WINDOW technique 
        int leftPtr = 0; 

        // declare variable to return as our result 
        int length = 0; 

        // 3. iterate thr our given string 
            // where our rightPtr is used as the ITERATOR for the for-loop 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check for duplicates / update window accordingly 
            while(charsVisited.find(s[rightPtr]) != charsVisited.end())
            {
                // oh no! dup found! :( --> NEED TO UPDATE WINDOW
                // take out val from leftPtr
                charsVisited.erase(s[leftPtr]); 

                // update leftPtr now to next val --> officially updates window 
                leftPtr++; 
            }

            // if no dups found --> insert new val into hashSet 
            charsVisited.insert(s[rightPtr]); 

            // update our max substring length now 
            length = max(length, rightPtr - leftPtr + 1); 
        }

        return length; 
    }
};