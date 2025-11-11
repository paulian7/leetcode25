class Solution {
public:
    int search(vector<int>& nums, int target) {
        // tech: 
            // array sorted --> binary search
            // sorted, but could be dealing w/ a rotated array lol
            // want to return index of value specified by target 
                // return -1 if can't find 
        
        // time & space comp: 
            // time: o(logn)
                // BINARY SEARCH -- way to go if want time comp < o(n)
            // space: o(1) 
        
        // 1. create our pointers 
        int leftPtr = 0; // low 
        int rightPtr = nums.size() - 1; // high 

        // 2. iterate thr array
        while(leftPtr <= rightPtr)
        {
            // calc midPt to halve our search space (since we're doing binary search)
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // CASE 1 == CHECK IF OUR MIDPT IS OUR TARGET VAL
            if(target == nums[midPt])
            {
                return midPt; // return midPt's index :)
            }

            // CASE 2 - figure out which halve to search for target (left or right)
            if(nums[leftPtr] <= nums[midPt])
            {
                // midPt val belongs to LEFT sorted portion.... 
                // so, focus on left portion here
                if(target > nums[midPt] || target < nums[leftPtr])
                {
                    // need to switch to right portion here...
                    leftPtr = midPt + 1;
                }
                else 
                {
                    // can stay in left portion!! 
                    // need to update rightPtr then to left halve 
                        // this narrows down our search space further
                    rightPtr = midPt - 1;
                }
            }
            else 
            {
                // midPt val belongs to RIGHT sorted portoin
                if(target < nums[midPt] || target > nums[rightPtr])
                {
                    // switch to left portion...
                    rightPtr = midPt - 1;
                }
                else 
                {
                    // can stay in right portion!
                    leftPtr = midPt + 1;
                }
            }

        }

        // worst case, return -1 
        return -1; 
    }
};