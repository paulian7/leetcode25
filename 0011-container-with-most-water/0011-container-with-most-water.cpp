class Solution {
public:
    int maxArea(vector<int>& height) {
        // the largest area - 
            // length * height 
        
        // time complexity: o(n) 
        // space complexity: o(1) 
        
        // 2 pointers 
        int leftPtr = 0; 
        int rightPtr = height.size() - 1; 

        // var to return as our final result 
        int maxAmnt = 0; 

        while(rightPtr > leftPtr)
        {
            // to check what our currArea is right now 
            int currArea = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr]); 

            // want to update result var accordingly 
            maxAmnt = max(maxAmnt, currArea); 

            // to maximize the height 
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
                leftPtr++; 
            }
        }

        return maxAmnt; 
    }
};