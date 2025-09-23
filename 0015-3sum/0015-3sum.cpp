class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // tech: sort && 2 pointers method

        // time & space comp: 
            // time: o(nlogn * n^2)
                // o(nlogn) -- sort() method used 
                // n^2 -- our nested loops being used 
                    // 1st loop - used for 1st val within the triplet
                    // 2nd loop - used for the last 2 values within the triplet
            // space: 
                // o(1) -- as sort is in-place 
                // o(m) -- IF, we count the output array
                    // m - being the number of triplets
        
        // 1. sort array -- helps us to identify duplicates easier
        sort(nums.begin(), nums.end());

        // 2. declare vector to return our result
        vector<vector<int>> resultTriplets;

        // 3. start iterating thr our array 
        for(int i = 0; i < nums.size(); i++)
        {
            // DEAL W/ OUR FIRST ELEMENT WITHIN THE TRIPLET
            // ensure that we're not dealing w/ duplicates first 
            if(i > 0 && nums[i] == nums[i - 1]) continue; // continue to the NEXT ITERATION

            // now -- deal w/ our next 2 vals for our triplet
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1; 
            while(leftPtr < rightPtr)
            {
                // calculate curr triplet sum we're dealing w/
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr]; 

                // adjust our currSum accordingly if needed 
                if(currSum > 0)
                {
                    // adjust rightPtr
                    rightPtr--; 
                }
                else if(currSum < 0)
                {
                    // adjust leftPtr 
                    leftPtr++; 
                }
                else 
                {
                    // we're dealing w/ our currSum == 0 :D! 
                    // add it to our result vector 
                    resultTriplets.push_back({nums[i] + nums[leftPtr] + nums[rightPtr]});

                    // update 1 ptr -- no need for both as if-conditions will take care of that 
                    leftPtr++; 

                    // ensure our updated ptr didn't hit into any duplicates 
                    while(leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1])
                    {
                        leftPtr++;
                    }
                }
            }
        }
        
        return resultTriplets;
    }
};