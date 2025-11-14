class Solution {
public:
    int search(vector<int>& nums, int target) {
        // tech: the default binary search 

        // time & space comp: 
            // time: o(logn) 
                // search space is halved @ each iteration 
            // space: o(1) 
                // search is in-place
        
        // 1. declare pointers to be used in binary search
        int leftPtr = 0;
        int rightPtr = nums.size() - 1;
        while(leftPtr <= rightPtr)
        {
            // calc midPt 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // check to see if midPt's val is == target 
            if(nums[midPt] == target)
            {
                return midPt; 
            }

            // else, decide which half to search 
            if(target > nums[midPt])
            {
                // want to switch to the bigger half
                leftPtr = midPt + 1; 
            }
            else 
            {
                // want to switch to the smaller half
                rightPtr = midPt - 1;
            }
        }
        
        return -1;
    }
};