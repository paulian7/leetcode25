class Solution {
public:
    int search(vector<int>& nums, int target) {
        // tech: binary search --> time comp: o(logn)
            // always do binary search if we want something better...
            // ... than o(n)
        
        // 1. declare our pointers for binary search 
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1;
        
        // 2. iterate thr the array
        while(leftPtr <= rightPtr)
        {
            // declare midPt 
            int midPoint = leftPtr + (rightPtr - leftPtr) / 2;

            // CASE 1 -- check if midPt could be our target value 
            if(target == nums[midPoint])
            {
                return midPoint; // returns the index
            }

            // CASE 2 -- when we need to check left and right portions
            if(nums[leftPtr] <= nums[midPoint]) 
            {
                // dealing w/ left portion here 
                if(target > nums[midPoint] || target < nums[leftPtr])
                {
                    // switch to looking at right side 
                    leftPtr = midPoint + 1;
                }
                else 
                {
                    // when target's less than midPt but > leftPtr
                    // stay in left portion 
                    rightPtr = midPoint - 1;
                }
            }
            else 
            {
                // dealing with right side 
                if(target < nums[midPoint] || target > nums[rightPtr])
                {
                    // switch to left portion actually 
                    rightPtr = midPoint - 1;
                }
                else 
                {
                    leftPtr = midPoint + 1;
                }
            }
        }
        
        return -1; // worst case return
    }
};