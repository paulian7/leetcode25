class Solution {
public:
    int findMin(vector<int>& nums) {
        // tech: 
            // "sorted array" --> binary search 
            // o(logn) --> binary search 
            // rotated --> binary search 

        // time & space comp: 
            // time: o(logn)
            // space: o(1)
        
        // 1. declare result to return @ end
            // set to first val in array for now 
        int minVal = nums[0];

        // 2. declare & initialize the 2 pointers we're working w/ for binary search
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1; 

        // 3. perform binary search now
        while(leftPtr <= rightPtr)
        {
            // check if our search space is ordered in the way we want
            if(nums[leftPtr] < nums[rightPtr])
            {
                minVal = min(minVal, nums[leftPtr]); 
                break;
            }

            // find what search space will now be -- updated search space
                // i.e what half we'll be looking @ now
            int midPt = leftPtr + (rightPtr - leftPtr) / 2; 
            minVal = min(minVal, nums[midPt]); 
            if(nums[midPt] >= nums[leftPtr])
            {
                // midPt is apart of increasing section
                // want to search right section then
                // as anything before it will just increase
                leftPtr = midPt + 1; 
            }
            else 
            {
                // want to search left portion -
                    // for anything smaller
                rightPtr = midPt - 1;
            }
        }

        // 4. return final result 
        return minVal;
    }
};