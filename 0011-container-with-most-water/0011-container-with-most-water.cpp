class Solution {
public:
    int maxArea(vector<int>& height) {
        // declare result to return @ the end 
        int maxArea = 0; 

        // declare pointers for 2 pointers method 
        int leftPtr = 0; 
        int rightPtr = height.size() - 1; 
        while(leftPtr < rightPtr)
        {
            // cond 
            int currArea = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr]);
            // update maxArea accordingly
            maxArea = max(maxArea, currArea); 

            // update pointers accordingly 
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
                // pick a random pointer to update 
                leftPtr++;
            }
        }

        return maxArea;
    }
};