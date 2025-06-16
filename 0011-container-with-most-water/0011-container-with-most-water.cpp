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

        // 3. iterate thr array now searching for the longest length 
            // moving only the ptrs that's the smallest btwn the 2 ptrs 
            // bc we want the LARGEST height 
        while(leftPtr < rightPtr)
        {
            // 4. calc curr area: length * height 
                // want smallest height in calc to avoid any overflowing 
            int areaCalc = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr]); 

            // update max area accordingly now after calc 
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
                // when both ptrs same val in height --> can pick one to just update 
                rightPtr--; 
            }
        }

        return result; 
    }
};