class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // tech: sort && 2 pointers method
            // want to avoid duplicates --> sort() - helps us w/ this! 
        
        // time & space comp: 
            // time: o(nlogn) * o(n^2) 
                // nlogn -- sort() method being used 
                // n^2 -- 1st loop deals w/ 1st val in triplet
                    // 2nd loop deals w/ last 2 vals (2-ptrs method used)
            // space: o(1) 
                // sort done in place 
                // UNLESS - count output array
                    // o(m) -- m, num of triplets 
        
        // 1. declare array to return as result 
        vector<vector<int>> resTriplets;

        // 2. sort array before starting
        sort(nums.begin(), nums.end());

        // 3. start executin' 
        for(int i = 0; i < nums.size(); i++)
        {
            // ensure 1st value isn't a duplicate 
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // once ensured not a duplicate, set-up our 2-ptrs method execution 
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1;
            while(leftPtr < rightPtr)
            {
                // grab the curr tripletSum to see where we're at! 
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr];

                // update pointers accordingly if != 0 and add to result if == 0
                if(currSum > 0)
                {
                    // need to update rightPtr bc it points @ too big of a value
                    rightPtr--;
                }
                else if(currSum < 0)
                {
                    // need to update leftPtr bc it points @ too SMALL of a value
                    leftPtr++;
                }
                else 
                {
                    // WHEN CURRSUM == 0 :D

                    // add to res vector 
                    resTriplets.push_back({nums[i], nums[leftPtr], nums[rightPtr]});

                    // update 1 ptr... no need for both as that'll be taken care of by our if-conditions above
                    leftPtr++; 

                    // ensure leftPtr didn't hit us into a duplicate
                    while(leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1])
                    {
                        leftPtr++;
                    }
                }
            }
        }

        return resTriplets;
    }
};