class Solution {
public:
    int search(vector<int>& nums, int target) {
        // tech: 
            // binary search 
                // sorted array! 
                // rotated array :(
                // want search done in o(logn) 
        
        // time & space comp: 
            // time: o(logn) 
                // search space is halved each iteration
            // space: o(1) 
        
        // 1. create 2 pointers for binary search
        int leftPtr = 0; // low
        int rightPtr = nums.size() - 1; // high

        // 2. perform search
        while(leftPtr <= rightPtr)
        {
            // calc midPt to help decide search space later 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // CASE 1 == check if midPt is our target val
            if(nums[midPt] == target)
            {
                return midPt; // return midPt's index --> as it points to target
            } 

            // CASE 2 == figure out which half to search to find target
            if(nums[leftPtr] <= nums[midPt])
            {
                // --- midPt val belongs to LEFT SORTED portion ---
                // so, focus on left portion here 
                if(target > nums[midPt] || target < nums[leftPtr])
                {
                    // need to switch portions now - bc this one is invalid
                        // switch to right portion!
                    leftPtr = midPt + 1; 
                }
                else 
                {
                    // can stay in left portion - 
                    // need to update rightPtr then to left half!...
                        // which narrows our search space down further 
                    rightPtr = midPt - 1;
                }
            }
            else 
            {
                // --- midPt val belongs to RIGHT SORTED portion ---
                if(target < nums[midPt] || target > nums[rightPtr])
                {
                    // switch to left portion... 
                    rightPtr = midPt - 1;
                }
                else 
                {
                    // otherwise, stay in right portion 
                    leftPtr = midPt + 1;
                }
            }
        }

        // worst case, return -1 
        return -1;
    }
};