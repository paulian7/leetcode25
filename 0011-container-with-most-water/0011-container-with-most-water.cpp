class Solution {
public:
    int maxArea(vector<int>& height) {
        // tech: 2 pointers! -- let's us maximize length 

        // time & space comp: 
            // time: o(n) 
            // space: o(1)

        // 0. declare var to return as result 
        int maxArea = 0; 

        // 1. declare & initialize 2 pointers 
        int leftPtr = 0; 
        int rightPtr = height.size() - 1;

        // 2. execute 2 pointers method now -- 
        while(leftPtr < rightPtr)
        {
            // check currArea
                // length * width 
            int currArea = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr]);

            // update maxArea 
            maxArea = max(currArea, maxArea);

            // see if we can maximize our heights
            if(height[leftPtr] < height[rightPtr])
            {
                leftPtr++; // search for a larger height w/ left
            }
            else if(height[rightPtr] < height[leftPtr])
            {
                rightPtr--; // search for a larger height w/ right
            }
            else 
            {
                // both ptrs point to same height... just update 1 
                leftPtr++;
            }
        }

        // once while-loop finishes, return final result
        return maxArea;
    }
};