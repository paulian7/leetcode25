class Solution {
public:
    int findMin(vector<int>& nums) {
        // declare result to return @ end
        int minVal = nums[0];

        // declare pointers for binary search 
        int leftPtr = 0;
        int rightPtr = nums.size() - 1;

        // perform binary search 
        while(leftPtr <= rightPtr)
        {
            // check if we're already in a sorted part of the array 
            if(nums[leftPtr] < nums[rightPtr])
            {
                minVal = min(minVal, nums[leftPtr]); 
                break;
            }

            // need to figure out which half! 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2; 
            if(nums[leftPtr] <= nums[midPt])
            {
                // apart of increasing section.... want to switch to smaller vals
                leftPtr = midPt + 1;
            }
            else 
            {
                // want to go left to see smaller vals
                rightPtr = midPt - 1;
            }
        }

        return minVal;
    }
};