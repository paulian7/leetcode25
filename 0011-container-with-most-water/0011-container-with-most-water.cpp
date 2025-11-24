class Solution {
public:
    int maxArea(vector<int>& height) {
        // tech: 
            // 2 pointers method! 
                // want to find largest area 
                // can maximize length by having 2 pointers at beg & end 
        
        // time & space comp: 
            // time: o(n)
            // space: o(1)
        
        // 1. declare var to return @ end 
        int maxArea = 0; 

        // 2. execute 2 pointers method 
        int leftPtr = 0; 
        int rightPtr = height.size() - 1; 

        while(leftPtr < rightPtr)
        {
            // 3. check for curr area 
                // length * height 
                    // want to minimize the height so no overflow occurs 
            int currArea = (rightPtr - leftPtr) * min(height[leftPtr], height[rightPtr]);

            // 4. update maxArea accordingly 
            maxArea = max(maxArea, currArea);

            // 5. see if we can maximize the heights now by adjusting the pointers 
            if(height[leftPtr] < height[rightPtr])
            {
                leftPtr++; // update left bc left too small 
            }
            else if(height[rightPtr] < height[leftPtr])
            {
                rightPtr--; // update rightPtr bc right too small 
            }
            else 
            {
                // both heights are the same val... can just update one height then 
                leftPtr++;
            }
        }

        // return result 
        return maxArea;
    }
};