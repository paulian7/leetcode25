class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // tech: 
            // sort, 2 pointers method (for the last 2 of the 3 vals used in 3-sum)
        
        // time & space comp: 
            // time: 
                // sort - o(nlogn) 
                // 2 pointers used for last 2 vals & outer loop used for 1st val: o(n^2) 
            // space: 
                // sorting done in-place --> o(1) 
                // if output array is counted - o(m) 
                    // m - being the number of triplets we're dealing w/ 
        
        // 1. sort array first 
        sort(nums.begin(), nums.end());

        // 2. declare vector to hold our result 
        vector<vector<int>> result;

        // 3. start iterating thr the array 
        for(int i = 0; i < nums.size(); i++)
        {
            // deal w/ the first val in the triplet 
                // always skip to the next iteration if we're dealing w/ a duplicate
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // otherwise, deal w/ the other 2 vals now... 
                // START executing the TWO POINTERS METHOD
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1; 
            while(leftPtr < rightPtr)
            {
                // get curr val of our triplet 
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr]; 

                // adjust the pointers accordingly now (based on the currSum)
                if(currSum > 0)
                {
                    rightPtr--; // needs to lower down bc it's pointing at TOO big of a value
                }
                else if(currSum < 0)
                {
                    leftPtr++; // needs to increment leftPtr bc it's pointing at TOO small of a value
                }
                else 
                {
                    // FOUND A TRIPLET == 0 :)

                    // push_back() to result vector
                    result.push_back({nums[i], nums[leftPtr], nums[rightPtr]}); 

                    // now update one of our pointers -- don't need to necessarily update both...
                        // as our if conditions above will take care of that for us
                    leftPtr++; 

                    // ... ensure after updating leftPtr... 
                        // that no duplicates have been crossed 
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