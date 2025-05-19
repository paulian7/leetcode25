class Solution {
public:
    int maxArea(vector<int>& height) {
        // tech: 2 pointers approach - time comp: o(n) 
            // main goal: to maximize the length while also maximizing the height 
            // have pointers be in their own respective sides
        
        // 1. declare variable to return 
        int result = 0;

        // 2. declare / initialize our 2 pointers 
        int leftPtr = 0; 
        int rightPtr = height.size() - 1;

        // 3. iterate thr array now searching for the largest length 
            // moving only the ptrs that's the smallest btwn the 2 ptrs
                // as we're searching for the largest height
        while(leftPtr < rightPtr)
        {
            // 4. calc curr area: length * height 
                // want smallest height in calc to avoid any overflowing 
            int areaCalc = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr]);

            // update max area accordingly now after calculation 
            result = max(result, areaCalc); 

            // now update ptrs to maximize heights 
            if(height[leftPtr] < height[rightPtr])
            {
                leftPtr++;
            }
            else if(height[rightPtr] < height[leftPtr])
            {
                rightPtr--;
            }
            else 
            {
                rightPtr--; // when both ptrs same val.. just update 1
            }
        }

        return result;
    }
};