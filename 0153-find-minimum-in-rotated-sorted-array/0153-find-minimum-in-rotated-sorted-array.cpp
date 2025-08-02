class Solution {
public:
    int findMin(vector<int>& nums) {
        // tech: 
            // bc array was sorted --> hints BINARY SEARCH should be used
            // will be doing binary search w/ a twist
            // will identify pivot within array 
        
        // time & space comp: 
            // time: o(logn)
            // space: 

        // 1. declare & initialize our result var to return 
            // have default val to first element in array fOR NOW
        int result = nums[0];

        // 2. declare & initialize our 2 pointers 
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1; 

        // 3. iterate thr our array now
        while(leftPtr <= rightPtr)
        {
            // CASE 1 == CHECK IF ARRAY ALREADY SORTED BY DEFAULT
            if(nums[leftPtr] < nums[rightPtr])
            {
                result = min(result, nums[leftPtr]); 
                break; // BREAKS OUT OF WHILE-LOOP ENTIRELY
            }

            // CASE 2 - WHEN ARRAY HAS BEEN ROTATED..
                // need to find mindpoint -- what binary search does.. divides search space in half
                    // l + (r - l) / 2 
                        // ^ calc midPt 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2; 
            // check if midPt could poss be smallest val
            result = min(result, nums[midPt]); 

            // NOW decide if we search LEFT or RIGHT sections
            if(nums[midPt] >= nums[leftPtr]) // midPt is apart of left sorted portion (the big vals)
            {
                // so we want to search right portion (bc they should contain the smaller vals)
                    // update leftPtr then to go to smaller vals portion 
                leftPtr = midPt + 1;
            }
            else 
            {
                // we're dealing w/ the right sorted portion... so we want to search left...
                    // bc anything from searching right would just increase..
                    // and we don't want increasing vals
                rightPtr = midPt - 1;
            }
        }

        return result;
    }
};