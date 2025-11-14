class Solution {
public:
    int findMin(vector<int>& nums) {
        // tech: binary search 
            // sorted, rotated, time comp of logn is wanted

        // 1. declare result to return 
        int minVal = nums[0]; 

        // 2. set up binary search 
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1;
        while(leftPtr <= rightPtr)
        {
            // check if in sorted portion immediately 
            if(nums[leftPtr] < nums[rightPtr])
            {
                minVal = min(minVal, nums[leftPtr]); 
                break;
            }

            // binary search steps...
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;
            // check if midPt's val could be the smallest val
            minVal = min(minVal, nums[midPt]);

            // check for which portion to look into now 
            if(nums[leftPtr] <= nums[midPt])
            {
                leftPtr = midPt + 1;
            }
            else 
            {
                rightPtr = midPt - 1;
            }
        }

        return minVal;
    }
};