class Solution {
public:
    int findMin(vector<int>& nums) {
        // tech: 
            // sorted, rotated, time comp of o(logn) desired --> binary search
        
        // time & space comp: 
            // time: o(logn) 
                // using binary search 
            // space: o(1) 
                // in-place search algorithm

        // 1. declare result to return as final answer 
            // set to first val in array so far
        int minVal = nums[0]; 

        // 2. set up 2 pointers used for binary search
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1; 

        // 3. start our search
        while(leftPtr <= rightPtr) 
        {
            // check for condition -- of whether or not we're already in a sorted search space 
            if(nums[leftPtr] < nums[rightPtr])
            {
                minVal = min(minVal, nums[leftPtr]); 
                break;
            }

            // otherwise -- start steps of binary search 
            // calculate our midPoint -- what we use to help us decide which half to search
                // by doing it this way, it helps us avoid any integer overflow 
                // is still the same as (leftPtr + rightPtr) / 2 -- but this way helps prevent overflow
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // check if midPt can poss be minVal 
            minVal = min(minVal, nums[midPt]); 
            
            // decide which half to search 
            if(nums[leftPtr] <= nums[midPt])
            {
                // midPt apart of increasing section -- want to swap to other section 
                leftPtr = midPt + 1; 
            }
            else 
            {
                // want to search left -> to see if there's any smaller values 
                rightPtr = midPt - 1; 
            }
        }

        // if no min val can be found 
        return minVal;
    }
};