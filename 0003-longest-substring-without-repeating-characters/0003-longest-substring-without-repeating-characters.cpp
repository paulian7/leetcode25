class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // tech: sets & sliding window --> time & space comp: o(n) 
            // tldr - want subarray w/ no duplicates
            // sets help us as they don't allow duplicates 
        
        // 1. declare a set 
        unordered_set<int> charsVisited; 

        // 2. declare / initialize our 2 pointers for sliding window 
        int leftPtr = 0; 
        
        // var to return 
        int length = 0;

        // 3. iterate thr string 
        for(int rightPtr = 0; rightPtr < s.length(); rightPtr++)
        {
            // check for duplicates and update window accordingly
            while(charsVisited.find(s[rightPtr]) != charsVisited.end())
            {
                // dup found - so need to remove the val leftPtr was at from set
                charsVisited.erase(s[leftPtr]);
                // update leftPtr now to next val - thereby updatingo ur window
                leftPtr++;
            }

            // if no duplicates --> look at rightmost values now 
            charsVisited.insert(s[rightPtr]);
            
            // update max substring length 
            length = max(length, rightPtr - leftPtr + 1);
        }

        return length;
    }
};