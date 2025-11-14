class Solution {
public:
    int search(vector<int>& nums, int target) {
        // tech: binary search!! bc...
            // sorted 
            // rotated 
            // time comp of o(logn) is wanted

        // 1. declare pointers for binary search 
        int leftPtr = 0;
        int rightPtr = nums.size() - 1; 

        // 2. start binary search algorithm
        while(leftPtr <= rightPtr)
        {
            // calc midPt 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // check if midPt could poss be our target 
            if(nums[midPt] == target)
            {
                return midPt;
            }

            // need to figure out which half to search into 
            if(nums[leftPtr] <= nums[midPt])
            {
                // want to check if we can stay in this half or not 
                if(target < nums[leftPtr] || target > nums[midPt])
                {
                    // want to swap halves
                    leftPtr = midPt + 1;
                }
                else 
                {
                    // can stay in this half! 
                    rightPtr = midPt - 1;
                }
            }
            else 
            {
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

        // 3. return -1 in the case you don't find the target at all 
        return -1; 
    }
};