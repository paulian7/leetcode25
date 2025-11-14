class Solution {
public:
    int search(vector<int>& nums, int target) {
        // establish pointers 
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1; 

        // perform binary search 
        while(leftPtr <= rightPtr)
        {
            // calc midPt 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // check if midPt is == target 
            if(nums[midPt] == target)
            {
                return midPt; 
            }

            // figure out which half to check
            if(target > nums[midPt])
            {
                leftPtr = midPt + 1; 
            }
            else 
            {
                rightPtr = midPt - 1;
            }
        }

        return -1;
    }
};