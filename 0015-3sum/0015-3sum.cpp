class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // tech: 
            // don't want any duplicates --> sort 
            // want 3 vals that add up to 0 --> can use 2 pointers to cover 2 vals
        
        // time & space comp: 
            // time: 
                // o(n^2) -- due to nested loops 
                // if we want to consider the sort() --> o(nlogn) 
            // space: 
                // o(1) if output excluded 
                // o(m) -- otherwise if output included... m being num of triplets
        
        // 0. establish an array to store all our triplets that == 0
        vector<vector<int>> result;

        // 1. sort array first -- helps us avoid any duplicates
        sort(nums.begin(), nums.end());

        // 2. start iterating thr array 
        for(int i = 0; i < nums.size(); i++)
        {
            // check for duplicates first 
            if(i > 0 && nums[i] == nums[i - 1]) continue; 

            // establish 2 pointers for our next to values
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1;
            while(leftPtr < rightPtr)
            {
                // check current sum so far 
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr]; 

                // adjust sum accordingly or add triplet 
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
                    // currSum == 0 :) --> want to add as a triplet 
                    result.push_back({nums[i], nums[leftPtr], nums[rightPtr]});

                    // want to update pointers 
                        // only have to update 1 bc our if-conditions above will adjust everything else accord.
                    leftPtr++; 

                    // want to ensure that we haven't hit into a duplicate w/ leftPtr 
                    while(leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1])
                    {
                        leftPtr++;
                    }
                }
            }
        }

        return result;
    }
};