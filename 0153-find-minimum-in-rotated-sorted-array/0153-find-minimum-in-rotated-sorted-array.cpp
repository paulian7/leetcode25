class Solution {
public:
    int findMin(vector<int>& nums) {
        // tech: 
            // binary search! -- want time comp of o(logn), array sorted (but rotated))
        
        // time & space comp: 
            // time: o(logn) 
            // space: o(1) 
        
        // 1. declare & initialize our result var to return 
            // have smallest val be first element in arr for now 
        int minVal = nums[0];

        // 2. declare & initialize 2 pointers for BINARY SEARCH
        int leftPtr = 0; 
        int rightPtr = nums.size() - 1;

        // 3. BEGIN BINARY SEARCH ==
        while(leftPtr <= rightPtr)
        {
            // CASE1 == CHECK IF SUBARRAY SORTED 
            if(nums[leftPtr] < nums[rightPtr])
            {
                minVal = min(minVal, nums[leftPtr]);
                break; // BREAKS OUT OF WHILE-LOOP ENTIRELY
            }

            // CASE 2 == WHEN ARR HAS BEEN ROTATED...
                // need to find midPt to start performing biinary search
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // check if midPt could poss be smallestVal 
            minVal = min(minVal, nums[midPt]);

            // decide to search in left or right section 
            if(nums[midPt] >= nums[leftPtr])
            {
                // then... midPt part of left sorted portion (big vals)
                // so want to search right portion instead 
                    // bc they should contain the smaller vals
                // update leftPtr to search RIGHT HALF now
                leftPtr = midPt + 1; 
            }
            else 
            {
                // want to search left portion 
                rightPtr = midPt - 1;
            }
        }

        return minVal;
    }
};