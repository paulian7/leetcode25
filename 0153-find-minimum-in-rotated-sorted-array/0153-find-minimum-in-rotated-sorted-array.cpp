class Solution {
public:
    int findMin(vector<int>& nums) {
        // tech: 
            // binary search: sorted, rotated, logn time comp
            // will need to identify a pivot
        
        // time & space comp: 
            // time: o(logn) 
                // typical time comp of binary search
            // space: o(1)
        
        // 1. declare & initialize our result var to return @ the end 
            // default it to the first val in array for now
        int minVal = nums[0];

        // 2. declare & initialize 2 pointers we're working w/ for binary search
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1;

        // 3. perform binary search 
        while(leftPtr <= rightPtr)
        {
            // CASE 1 == CHECK IF SUBARRAY SORTED -- our current search space
            if(nums[leftPtr] < nums[rightPtr])
            {
                minVal = min(minVal, nums[leftPtr]); 
                break; // break statement -- breaks out of nearest enclosing loop (aka our while-loop)
            }

            // CASE 2 == WHEN ARR IS ROTATED, dealing w/ strange order
                // need to find midPt to start performing binary search
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // check if midPt could poss be smallest val
            minVal = min(minVal, nums[midPt]);

            // decide to search in left or right section / side 
            if(nums[midPt] >= nums[leftPtr])
            {
                // then.. midPt part of left sorted portion (the big vals).. bc everything's increasin' here
                // so want to search right portion instead 
                    // bc it should contain the smaller vals
                // update leftPtr to search RIGHT HALF now 
                leftPtr = midPt + 1;
            }
            else 
            {
                // want to search LEFT PORTION
                rightPtr = midPt - 1; 
            }
        }

        // 4. return final result
        return minVal;
        
    }
};