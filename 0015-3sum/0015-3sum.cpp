class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort() - o(nlogn) 
        sort(nums.begin(), nums.end()); 

        // declare variable to return 
        vector<vector<int>> resTriplet; 

        // 1 for-loop --> time comp: o(n) 
            // sole focus - looking at 1st element within triplet 
            // then - we'll have a while loop 
                // 2 pointers --> time comp: o(n) 
        for(int i = 0; i < nums.size(); i++)
        {
            // check for any duplicates right off the bat 
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue; 
            }

            // if no duplicates - then identify next to elements for our triplet 
            int leftPtr = i + 1; 
            int rightPtr = nums.size() - 1; 
            // execute 2 pointers method 
            while(leftPtr < rightPtr)
            {
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr]; 
                
                // update pointers accordingly 
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
                    // when the currSum is ACTUALLY 0 
                    
                    // want to store this answer to return 
                    resTriplet.push_back({nums[i], nums[leftPtr], nums[rightPtr]}); 

                    // want to update ptrs (only need to do 1)
                    leftPtr++; 

                    // want to ensure that the value leftPtr points at now 
                        // DOES NOT HIT A DUPLICATE 
                    while(leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1])
                    {
                        leftPtr++; 
                    }
                }
            }
        }

        return resTriplet; 
    }
};