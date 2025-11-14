class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort array -- helps us identify duplicates easily 
        sort(nums.begin(), nums.end());

        // declare 2d vector to use as result to return @ the end 
        vector<vector<int>> triplets; 

        // iterate thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // check if we've ALREADY encountered a duplicate - if we're not lookin' @ our first val ofc
                // .. if yes, skip to next iteration of our loop entirely 
            if(i > 0 && nums[i - 1] == nums[i]) continue; 

            // else... let's start w/ our 2 pointers method 
            // 1) declare pointers 
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1;
            while(leftPtr < rightPtr)
            {
                // check curr condition 
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr];

                // update pointers accordingly now && actual check
                if(currSum > 0)
                {
                    rightPtr--;
                }
                else if(currSum < 0)
                {
                    leftPtr++;
                }
                else 
                {
                    // currSum is actually want we want --> a zero! 
                    triplets.push_back({nums[i], nums[leftPtr], nums[rightPtr]});

                    // update pointer for next iteration now...
                    leftPtr++; 
                    while(leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1])
                    {
                        leftPtr++;
                    }
                }
            }
        }

        return triplets;
    }
};