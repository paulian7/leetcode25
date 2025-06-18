class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // tech: hash sets --> time comp: o(n) 
        
        // 1. declare hash set 
        unordered_set<int> numSet(nums.begin(), nums.end()); 

        // var to return at end - tracks longest consec 
        int longest = 0; 

        // 2. iterate thr the array 
        for(int num : numSet)
        {
            // 3. want to check for the start of sequences 
                // if we can find the val that comes before our curr val...
                // ... that is NOT the start 
                // otherwise, if we can't --> we found a start! 
            if(numSet.find(num - 1) == numSet.end()) 
            {
                // so... we found the start of a sequence 
                int currLength = 1; // currLength of seq 
                while(numSet.find(num + currLength) != numSet.end())
                {
                    currLength++; 
                }

                // update length tracker
                longest = max(longest, currLength); 
            }
        }

        return longest; 
    }
};