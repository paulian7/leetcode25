class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // ?: want 3 different values that add up to 0

       // 1. sort as this helps us avoid duplicates 
       sort(nums.begin(), nums.end());  

       // vector of arrays of triplets to return as answer 
       vector<vector<int>> resultArray; 

       // 2. iterate thr array using a for-loop & inner while-loop
            // for-loop deals w/ first element in the triplet 
            // while loop deals w/ the other 2 elements in the triplet using 2 pointers

        for(int i = 0; i < nums.size(); i++)
        {
            // check 1: if > 0 --> then imposs to have valid triplet 
            if(nums[i] > 0) break; 
            // check 2: for dups --> if dup... continue to next iteration 
            if(i > 0 && nums[i] == nums[i - 1]) continue; 

            // 2 pointers method ----
                // deals w/ 2 other vals in the triplet 
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1; 
            while(leftPtr < rightPtr)
            {
                // calc sum first as conditional statement w/ the 2 pointers 
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr]; 

                // rightPtr check - if currSum too big --> need to lower val of rightPtr 
                if(currSum > 0)
                {
                    rightPtr--;
                }
                else if(currSum < 0) // too small --> need to lower val of leftPtr 
                {
                    leftPtr++; 
                }
                else // when our currSum actually equates to 0
                {
                    resultArray.push_back({nums[i], nums[leftPtr], nums[rightPtr]}); 

                    leftPtr++;
                    // ensure there's no duplicates after the update in pointers 
                    while(leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1])
                    {
                        leftPtr++;
                    }
                }
            }
        }

        return resultArray;
    
    }
};