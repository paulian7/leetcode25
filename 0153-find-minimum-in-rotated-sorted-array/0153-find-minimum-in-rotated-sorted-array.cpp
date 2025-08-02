class Solution {
public:
    int findMin(vector<int>& nums) {
        // tech: 
            // array sorted, rotated.. binary search! 
        // time & space comp: 
            // time: o(logn) <-- time comp of binary search
            // space: o(1) 
        
        // 1. declare & initialize our result var to return
            // have default val to first element in array FOR NOW
        int result = nums[0]; 

        // 2. declare & initialize our 2 pointers to prep for binary search
        int leftPtr = 0; // smallest val
        int rightPtr = nums.size() - 1; // largest val

        // 3. BEGIN BINARY SEARCH! ===
        while(leftPtr <= rightPtr)
        {
            // CASE 1 == CHECK IF ARRAY SORTED ALREADY BY DEFAULT 
            if(nums[leftPtr] < nums[rightPtr])
            {
                result = min(result, nums[leftPtr]);
                break; // BREAKS OUT OF WHILE-LOOP ENTIRELY
            }

            // CASE 2 == WHEN ARRAY HAS BEEN ROTATED..
                // need to find midpt - what binary search does 
                    // divides search area in half
                    // l + (r - l) / 2 
                        // ^ calculates the midPt 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // check if midPt could poss be smallest val
            result = min(result, nums[midPt]);

            // now decide if we search LEFT or RIGHT section 
            if(nums[midPt] >= nums[leftPtr]) 
            {
                // midPt is apart of left sorted portion...(the big vals)
                // SO, we want to search the right portion 
                    // bc they should contian the smaller vals
                // update leftPtr then to go to the smaller vals portion 
                leftPtr = midPt + 1;
            }
            else 
            {
                // we're dealing w/ the right sorted portion, so we want to search left
                    // bc anything from searching right would just increase... 
                    // and we don't want increasing vals
                rightPtr = midPt - 1;
            }
        }
        
        return result;
    }
};