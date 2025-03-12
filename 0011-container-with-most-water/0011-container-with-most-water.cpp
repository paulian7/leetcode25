class Solution {
public:
    int maxArea(vector<int>& height) {
        // tech: 2 pointers approach - o(n) time comp
            // main goal: to maimize the width 
            // have pointers be in their own respective sides 
        
        // 1. declare variable to return 
        int result = 0; 

        // 2. declare / initialize our 2 pointers 
        int leftPtr = 0; // start of array 
        int rightPtr = height.size() - 1; // end of array 

        // 3. iterate thr array now searching for the largest width 
            // moving only the ptr that's the smallest btwn the 2 ptrs 
        while(leftPtr < rightPtr)
        {
            // 4. calc curr area: width * height 
                // want smallest height to avoid any overflowing 
            int areaCalc = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr]);

            // update max area accordingly 
            result = max(result, areaCalc); 

            // rmbr to update ptrs to maximize heights --> to help find max area 
            if(height[leftPtr] < height[rightPtr])
            {
                // left is smaller --> want to move it to grab a higher height 
                    // don't need to update right bc it's already high so why
                leftPtr++; // want to update left here bc left is too small 
            }
            else if(height[leftPtr] > height[rightPtr])
            {
                rightPtr--; // want to update right bc it's now too small 
            }
            else 
            {
                rightPtr--; // when both ptrs are the same value... just pick any ptr to update 
            }
        }

        return result;
    }
};