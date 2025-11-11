class Solution {
public:
    int findMin(vector<int>& nums) {
        // tech: binary search! 
            // rotated, sorted, logn time complexity wanted! 
        
        // time & space comp: 
            // time: o(logn)
            // space: o(1) 

        // 1. declare result to return @ end
        int minVal = nums[0];

        // 2. establish pointers to be used for binary search 
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1;

        // 3. perform search for minimum 
        while(leftPtr <= rightPtr)
        {
            // establish midPtr 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;
            minVal = min(minVal, nums[midPt]);

            // CASE 1 -- CHECK IF SORTED ARRAY? 
            if(nums[leftPtr] < nums[rightPtr])
            {
                minVal = min(minVal, nums[leftPtr]);
                break;
            }

            // CASE 2 -- need to perform binary search actually
                // figure out which half to search in 
            if(nums[midPt] >= nums[leftPtr])
            {
                // want to switch over to right portion... since midPt is apart of increasing vals portion 
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