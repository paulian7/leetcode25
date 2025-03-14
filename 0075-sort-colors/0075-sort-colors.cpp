class Solution {
public:
    void sortColors(vector<int>& nums) {
        // tech: using 3 pointers in total --> time comp: o(n)
            // p0 = rightmost boundary of 0s 
            // curr = index of curr element 
            // p2 = leftmost boundary of 2s 

        // 1. declare ptr to track rightmost boundary of 0s 
            // if curr element is 0 --> then it'll be swapped w/ element at p0 
            // p0 and curr then ++ 
        int p0 = 0; 
        int currPos = 0; 

        // 2. declare ptr to track leftmost boundary of 2s 
            // if curr element is 2 --. then it'll be swapped w/ element at p2 
            // p2 will then be moved to the left -- 
        int p2 = nums.size() - 1;

        while(currPos <= p2)
        {
            if(nums[currPos] == 0) // when element is 0 
            {
                swap(nums[currPos++], nums[p0++]);
            }
            else if(nums[currPos] == 2) // when element is 2 
            {
                swap(nums[currPos], nums[p2--]);
            }
            else // when element is 1 --> so no need to do any changes
            {
                currPos++;
            }
        }
    }
};