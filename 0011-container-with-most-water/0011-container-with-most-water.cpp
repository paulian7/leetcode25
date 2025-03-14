class Solution {
public:
    int maxArea(vector<int>& height) {
        // tech: 2 pointers approach - o(n) time comp 
            // main goal: to maximize the length while also maximizing the height 
            // have pointers be in their own respective sides 
        
        // 1. declare variable to return 
        int result = 0; 

        // 2. declare / initialize our 2 pointers 
        int leftPtr = 0; 
        int rightPtr = height.size() - 1;

        // 3. iterate thr array now searching for the largest length 
            // moving only the ptr that's smallest btwn the 2 ptrs (in search for largest height)
        while(leftPtr < rightPtr)
        {
            // 4. calc curr area: length * height 
                // want smallest height in calculation to avoid any overflowing 
            int areaCalc = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr]);

            // update max area accordingly now after calculation 
            result = max(result, areaCalc); 

            // now update ptrs now to maximize heights --> which in turn finds us max area 
            if(height[leftPtr] < height[rightPtr])
            {
                // left is smaller --> want to move it to grab a higher height 
                leftPtr++;
            }
            else if(height[leftPtr] > height[rightPtr])
            {
                rightPtr--; // want to update right bc it's now too small
            }
            else 
            {
                rightPtr--; // when both ptrs are the same value... just pick one value and update it
            }
        }

        return result;
    }
};