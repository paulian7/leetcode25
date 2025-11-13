class Solution {
public:
    int findMin(vector<int>& nums) {
        // tech: 
            // binary search - rotated, sorted, time comp of logn
        
        // time & space comp: 
            // time: o(logn)
                // w/ each iteration - the search space is HALVED
            // space: o(1) 
        
        // 1. declare result to return final answer
        int minVal = nums[0]; 

        // 2. set up pointers for binary search
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1; 

        // 3. execute binary search 
        while(leftPtr <= rightPtr)
        {
            // check case -
            if(nums[leftPtr] < nums[rightPtr])
            {
                minVal = min(minVal, nums[leftPtr]);
                break;
            }

            // else, need to find where to search 
                // ensure that there's no integer overflow by doing it this way 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;
            minVal = min(minVal, nums[midPt]);
            
            if(nums[leftPtr] <= nums[midPt])
            {
                // the increasing section --> want to swap to small section 
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