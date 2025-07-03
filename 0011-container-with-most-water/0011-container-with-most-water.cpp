class Solution {
public:
    int maxArea(vector<int>& height) {
        // WANT: 
            // optimize largest possible length

        // tech: 2 pointers technique 
        int leftPtr = 0; 
        int rightPtr = height.size() - 1; 

        int maxArea = 0; 

        while(leftPtr < rightPtr)
        {
            // calculate the area 
                // length * width 
            int currArea = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr]); 

            // update maxArea accordingly 
            maxArea = max(maxArea, currArea); 

            // update our pointers accordingly to MAXIMIZE our height 
            if(height[leftPtr] < height[rightPtr]) // leftPtr slacking 
            {
                leftPtr++; 
            }
            else if(height[rightPtr] < height[leftPtr]) // rightPtr slacking 
            {
                rightPtr--; 
            }
            else 
            {
                // both have the same height.. so we can just update 1 
                leftPtr++; 
            }
        }

        return maxArea; 
    }
};