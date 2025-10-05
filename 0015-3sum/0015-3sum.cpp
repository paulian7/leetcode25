class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // tech: 
            // want 3 vals adding up to a specific sum (i.e 0) 
            // can utilize 2 pointers here 
        
        // time & space comp: 
            // time: simplifies down to o(n^2)
                // o(nlogn) -- bc use sort()
                // o(n^2) -- bc of the nested loops
            // space: 
                // o(m) -- if we want to count the triplets in output array
        
        // 1. sort -- want to avoid duplicates 
        sort(nums.begin(), nums.end());

        // 2. iterate thr array -- also declaring array for our result 
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++)
        {
            // deal w/ 1st val -- ensure no duplicates 
            if(i > 0 && nums[i] == nums[i - 1]) continue; 

            // else, set up 2-pointers method 
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1; 
            while(leftPtr < rightPtr)
            {
                // check condition 
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr]; 
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
                    // currSum is actually equal to 0 --> so add to result 
                    result.push_back({nums[i], nums[leftPtr], nums[rightPtr]});

                    // update pointer now 
                    leftPtr++; 
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