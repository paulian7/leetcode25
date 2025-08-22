class Solution {
public:
    int search(vector<int>& nums, int target) {
        // tech: BINARY SEARCH
            // given sorted array, but could be rotated ;-;...
            // want to return target val's index
        
        // time & space comp: 
            // time: o(logn)
            // space: o(1)

        // 1. create pointers for binary search
        int leftPtr = 0;
        int rightPtr = nums.size() - 1;

        // 2. perform binary search algorithm 
        while(leftPtr <= rightPtr) 
        {
            // 3. calc midPt for binary search algo
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // check CASE 1 -- check if midPt is TARGET VAL
            if(target == nums[midPt])
            {
                return midPt; // return target's index (which is midPt)
            }

            // CASE 2 :( -otherwise, decide which half to search
            if(nums[leftPtr] <= nums[midPt])
            {
                // then... midPt belongs to LEFT portion... so focus here,
                if(target > nums[midPt] || target < nums[leftPtr])
                {
                    // need to switch halves
                    leftPtr = midPt + 1; 
                }
                else 
                {
                    // can stay in left portion! need to update right pointer then...
                    rightPtr = midPt - 1;
                }
            }
            else 
            {
                // midPt belongs to the RIGHT portion 
                if(target < nums[midPt] || target > nums[rightPtr])
                {
                    // need to switch halves 
                    rightPtr = midPt - 1;
                }
                else 
                {
                    // can stay in right portion! 
                    leftPtr = midPt + 1;
                }
            }
        }

        // WORST CASE - return -1
        return -1; 
    }
};