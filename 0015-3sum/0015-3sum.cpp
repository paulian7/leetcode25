class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // ?: want 3 diff values that add up to 0 

        // 1. sort() - helps us avoid duplicates 
            // does give us time comp w/ sorting of o(n logn)
        sort(nums.begin(), nums.end()); 

        // 2. declare vector of triplets to return as our answer 
        vector<vector<int>> res; 

        // 2. iterate thr array using a for-loop & inner while-loop 
            // for-loop - deals w/ first element in triplet 
            // while loop - deals w/ the other 2 elements in the triplet (using 2 pointers)
        for(int i = 0; i < nums.size(); i++)
        {
            // 3. check for dups first! 
            if(i > 0 && nums[i] == nums[i - 1]) continue; // aka go to next iteration bc dup 

            // 4. finally do our 2 pointers method for our other 2 vals in triplet 
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1; 
            while(leftPtr < rightPtr)
            {
                // calc sum first as conditional statement w/ the 2 pointers 
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr]; 

                // update pointers accordingly to the sum 
                if(currSum > 0) // rightPtr's val too big --> so decrement to find a smaller val 
                {
                    rightPtr--; 
                }
                else if(currSum < 0) // leftPtr's val too small --> so increment to find bigger val 
                {
                    leftPtr++; 
                }
                else 
                {
                    // currSum is ACTUALLY 0 
                    res.push_back({nums[i], nums[leftPtr], nums[rightPtr]}); 

                    // update pointers (really only need to do one though)
                        // as our conditional if's will help us out w/ the rest 
                    leftPtr++; 

                    // ensure no dups after leftPtr updated 
                    while(leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1])
                    {
                        leftPtr++; 
                    }
                }
            }
        }

        return res; 
    }
};