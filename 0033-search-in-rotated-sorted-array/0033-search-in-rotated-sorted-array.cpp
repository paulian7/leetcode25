class Solution {
public:
    int search(vector<int>& nums, int target) {
        // tech: binary search --> time comp: o(logn) 
            // binary search way to go if want time comp better than o(n)
        
        // 1. create our 2 pointers 
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1; 

        // 2. iterate thr the array now 
        while(leftPtr <= rightPtr)
        {
            int midPt = leftPtr + (rightPtr - leftPtr) / 2; 

            // case 1 - check if at the midPt we have target right away 
            if(target == nums[midPt])
            {
                return midPt; 
            }

            // otherwise - figure out which left or right portion to search for target 
            if(nums[leftPtr] <= nums[midPt])
            {
                // so, dealing w/ left portion bc leftVal < midPt val... 
                    // so vals just increase from left -> midPt 
                if(target > nums[midPt] || target < nums[leftPtr])
                {
                    // need to switch to right side for these scenarios 
                    leftPtr = midPt + 1; 
                }
                else 
                {
                    // can stay in this portion :)
                        // so update rightPtr to search left area 
                    rightPtr = midPt - 1; 

                }
            }
            else 
            {
                // so, dealing w/ right portion 
                    // as our midPt val can't increase from leftPt bc its too small and left too big
                if(target < nums[midPt] || target > nums[rightPtr])
                {
                    // damn got to switch to left portion now 
                    rightPtr = midPt - 1; 
                }
                else 
                {
                    // yay stay in right portion 
                    leftPtr = midPt + 1;
                }
            }
        }

        return -1; // worst case return of index
    }
};