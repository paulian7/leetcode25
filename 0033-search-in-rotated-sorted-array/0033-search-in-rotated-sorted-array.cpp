class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1; 

        while(leftPtr <= rightPtr)
        {
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;
            if(nums[midPt] == target)
            {
                return midPt; 
            }

            if(nums[leftPtr] <= nums[midPt])
            {
                if(target < nums[leftPtr] || target > nums[midPt])
                {
                    leftPtr = midPt + 1; 
                }
                else 
                {
                    rightPtr = midPt - 1;
                }
            }
            else 
            {
                if(target > nums[rightPtr] || target < nums[midPt])
                {
                    rightPtr = midPt - 1;
                }
                else 
                {
                    leftPtr = midPt + 1;
                }
            }
        }

        return -1;
    }
};