class Solution {
public:
    int findMin(vector<int>& nums) {
        // tech: binary search - time comp: o(logn)
        
        // 1. declare & initialize our result variable to return 
            // initialize to first element in array for now
        int result = nums[0]; 

        // 2. declare and initialize our 2 pointers 
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1;

        // 3. iterate thr our array now 
            // <= - the equal part ensures we cover all values 
        while(leftPtr <= rightPtr)
        {
            // CASE 1 == CHECK IF ARRAY ALREADY SORTED BY DEFAULT
            if(nums[leftPtr] < nums[rightPtr])
            {
                result = min(result, nums[leftPtr]);
                break; // breaks out of while-loop ENTIRELY 
            }

            // CASE 2 - WHEN ARRAY HAS BEEN ROTATED...

            // find midpoint first 
                // l + (r - l) / 2; <- formula to calc midPt in binary search 
                    // helps avoid overflow 
            int midPoint = leftPtr + (rightPtr - leftPtr) / 2;
            // check if midPoint could possibly be smallest val
            result = min(result, nums[midPoint]); 

            // now decide if we search either the left chunk or right chunk
            if(nums[midPoint] >= nums[leftPtr]) // midPtr part of left sorted portion (big vals)
            {
                // so we want to only search the right chunk 
                // update left val accordingly 
                leftPtr = midPoint + 1;
            }
            else // we're dealing with the right sorted portion (little baby values)
            {
                // want to search left chunk
                rightPtr = midPoint - 1;
            }
        }

        return result;
    }
};