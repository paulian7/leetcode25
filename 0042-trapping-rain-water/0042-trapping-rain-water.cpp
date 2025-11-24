class Solution {
public:
    int trap(vector<int>& height) {
        // tech: 2 pointers 

        // time & space comp: 
            // time: o(n)
            // space: o(1)

        // 1. deal w/ edge case 
        if(height.empty())
        {
            return 0;
        }

        // 2. establish 2 pointers 
        int leftPtr = 0; 
        int rightPtr = height.size() - 1;

        // 3. declare the max vals of leftPtr and rightPtr found so far
        int leftMax = height[leftPtr];
        int rightMax = height[rightPtr];

        // 4. declare result to return @ the end 
        int result = 0;

        // 5. execute 2-pointers method
        while(leftPtr < rightPtr)
        {
            // update pointers accordingly 
            if(leftMax < rightMax)
            {
                leftPtr++;
                leftMax = max(leftMax, height[leftPtr]);
                result += leftMax - height[leftPtr];
            }
            else 
            {
                rightPtr--;
                rightMax = max(rightMax, height[rightPtr]);
                result += rightMax - height[rightPtr];
            }
        }

        return result;
    }
};