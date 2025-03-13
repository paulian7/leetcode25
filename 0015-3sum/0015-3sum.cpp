class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array to help with avoiding duplicates
        sort(nums.begin(), nums.end());

        vector<vector<int>> resultArray;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate elements to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Two pointers
            int leftPtr = i + 1;
            int rightPtr = nums.size() - 1;

            while (leftPtr < rightPtr) {
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr];

                if (currSum > 0) {
                    rightPtr--;
                } else if (currSum < 0) {
                    leftPtr++;
                } else {
                    // Found a valid triplet
                    resultArray.push_back({nums[i], nums[leftPtr], nums[rightPtr]});

                    // Move left pointer and skip duplicates
                    leftPtr++;
                    while (leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1]) {
                        leftPtr++;
                    }
                }
            }
        }

        return resultArray;
    }
};
