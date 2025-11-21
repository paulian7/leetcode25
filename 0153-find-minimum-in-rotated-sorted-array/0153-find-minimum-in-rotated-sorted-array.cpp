class Solution {
public:
    int findMin(vector<int>& nums) {
        // time: o(logn) 
        // space: o(1) 

        int minVal = nums[0];

        int leftPtr = 0; 
        int rightPtr = nums.size() - 1;
        while(leftPtr <= rightPtr)
        {
            if(nums[leftPtr] < nums[rightPtr])
            {
                minVal = min(minVal, nums[leftPtr]);
                break;
            }

            int midPt = leftPtr + (rightPtr - leftPtr) / 2;
            minVal = min(nums[midPt], minVal); 

            if(nums[midPt] >= nums[leftPtr])
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