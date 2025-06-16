class Solution {
public:
    int maxArea(vector<int>& height) {
        // tech: 2 pointers approach --> time comp: o(n) 
            // main goal: to maximize the length while also maximizing the height 
            // have pointers be in their own respective sides 
        
        // 1. declare var to return 
        int result = 0; 

        // 2. declare / initialize our 2 ptrs 
            // at opp ends as we want to maximize the length 
        int leftPtr = 0; 
        int rightPtr = height.size() - 1; 

        // 3. iterate thr array now -- searching for the longest valid length 
            // moving only the ptrs that's the smallest btwn the 2 
            // bc we ALSO want the largest height 
        while(leftPtr < rightPtr)
        {
            // 4. calc currArea: length * height 
                // want smallest height to avoid any overflowing 
            int areaCalc = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr]); 

            // update max area ccordingly now after recent calculation 
            result = max(result, areaCalc); 

            // now update ptrs to maximize heights 
            if(height[leftPtr] < height[rightPtr])
            {
                leftPtr++; // want to increase leftPtr's val height 
            }
            else if(height[rightPtr] < height[leftPtr])
            {
                rightPtr--; 
            }
            else 
            {
                // both ptrs same val in height --> can just pick one to update 
                rightPtr--; 
            }
        }

        return result; 
    }
};