class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // ?: want 3 diff values that add up to 0 

        // 1. sort() - helps us avoid duplicates 
            // does give us time complexity of o(nlogn) as we're sorting 
        sort(nums.begin(), nums.end()); 

        // 2. declare vector of triplets to return as our answer 
        vector<vector<int>> res; 

        // 3. iterate thr array using a for-loop & inner while-loop 
            // for-loop -- deals w/ first element in triplet 
            // while loop - deals w/ the other 2 elements in the triplet 
                // using the 2 pointers method here! 
        for(int i = 0; i < nums.size(); i++)
        {
            // === 4. DEALING WITH FIRST VAL WITHIN TRIPLET == 
            // check for dups first 
            if(i > 0 && nums[i] == nums[i - 1])
            {
                // found duplicate! -- want to skip to next iteration 
                    // (as we want to avoid dups in our triplet
                continue; 
            }

            // == 5. DEALING W/ OTHER 2 VALS WITHIN TRIPLET == 
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1; 
            while(leftPtr < rightPtr)
            {
                // calc sum first as a conditional statement w/ the 2 pointers 
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr]; 

                // update ptrs accordingly to the sum 
                if(currSum > 0)
                {
                    // rightPtr's val too big --> so decrement to find smaller val 
                    rightPtr--; 
                }
                else if(currSum < 0)
                {
                    // leftPtr's val too small --> so increment to find larger val 
                    leftPtr++; 
                }
                else 
                {
                    // currSum is FINALLY 0! <-- what we want! 

                    // add to res vector to store our VALID TRIPLET 
                    res.push_back({nums[i], nums[leftPtr], nums[rightPtr]}); 

                    // update pointers -- just need to update 1 
                        // as our conditional statements above will udpate accordingly for us 
                    leftPtr++; 

                    // ensure no duplicates in the leftPtr 
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