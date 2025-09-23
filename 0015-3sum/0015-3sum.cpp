class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // tech: 
            // want 3 vals that add up to 0
            // want to ensure no duplicate triplets are found 
        
        // time & space comp: 
            // time: o(n logn) + o(n^2)
                // simplifies down to o(n^2) 
                // sort() - o(nlogn) 
                // nested loops - o(n^2) 
            // space: 
                // if you count sort: o(1) 
                    // c++ does in-place 
                // output array: o(m) 
                    // m - num of triplets
        
        // 1. sort! --> time comp; o(n logn) :(
        sort(nums.begin(), nums.end());

        vector<vector<int>> result; // will hold our final answer of triplets

        // 2. start iterating thr 
        for(int i = 0; i < nums.size(); i++)
        {
            // deal w/ the first val in our triplet first 
            if(i > 0 && nums[i] == nums[i - 1]) continue; // skip to next iteration bc dup

            // otherwise, deal w/ our other 2 vals now 
                // will be executing the 2 pointers method here to do so 
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1; 
            while(leftPtr < rightPtr)
            {
                // get the curr triplet val 
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr]; 

                // adjust the pointers accordingly (based on the currSum)
                if(currSum > 0)
                {
                    rightPtr--; // needs to lower down bc it's pointing at a too big val
                }
                else if(currSum < 0)
                {
                    leftPtr++; // need to increase leftPtr bc it's pointing at too small
                }
                else 
                {
                    // we finally have a sum of 0! add it to our result vector 
                    result.push_back({nums[i], nums[leftPtr], nums[rightPtr]});

                    // now update our pointers -- dont need to necessarily update both
                    leftPtr++; 

                    // ensure after the update of leftPtr... we haven't hit a dup! :(
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