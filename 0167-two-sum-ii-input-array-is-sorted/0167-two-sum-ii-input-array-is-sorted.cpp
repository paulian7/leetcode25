class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // tech: 2 pointers 
        
        // time & space comp: 
            // time: o(n) 
            // space: o(1) 
        
        // 1. establish our 2 pointers
        int leftPtr = 0;
        int rightPtr = numbers.size() - 1; 

        // 2. execute 2 pointers method
        while(leftPtr < rightPtr)
        {
            // check curr condition 
            int currSum = numbers[leftPtr] + numbers[rightPtr];

            // check if need adjustment, else return indices that add up to target 
            if(currSum < target)
            {
                leftPtr++;
            }
            else if(currSum > target)
            {
                rightPtr--;
            }
            else 
            {
                // two vals do equal target!! -> return the indices + 1
                return {leftPtr + 1, rightPtr + 1};
            }
        }

        return {};
    }
};