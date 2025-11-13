class Solution {
public:
    int search(vector<int>& nums, int target) {
        // tech: 
            // sorted, rotated, time comp of o(logn) wanted 
        
        // time & space comp: 
            // time: o(logn) 
                // w/ each iteration --> we're halving the search space
            // space: o(1) 
        
        // 1. declare pointers to use for binary search 
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1; 

        // 2. start search 
        while(leftPtr <= rightPtr)
        {
            // calculate midPt 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2; 

            // check if midPt could possibly be our target value
            if(nums[midPt] == target)
            {
                return midPt;
            }

            // else, start looking for which half to search
            if(nums[leftPtr] <= nums[midPt])
            {
                // look into left portion - as midPt val is apart of increasing section 
                if(target < nums[leftPtr] || target > nums[midPt])
                {
                    // check to see if we need to search in another section 
                    leftPtr = midPt + 1;
                }
                else 
                {
                    // stay in this section 
                    rightPtr = midPt - 1;
                }
            }
            else 
            {
                // look into right portion
                if(target < nums[midPt] || target > nums[rightPtr])
                {
                    rightPtr = midPt - 1;
                }
                else 
                {
                    leftPtr = midPt + 1;
                }
            }
        }

        // 3. else, couldn't find target --> so return -1
        return -1;
    }
};