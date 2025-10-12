class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // tech: sliding window --> time comp: o(n) 
        
        // 1. declare variable to keep track of sum within a subarray 
        double sum = 0; 
        
        // 2. find our very first subarray 
            // adding sum of entire array up until desired length 
            // is the first subarray w/ size of k 
        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        
        // 3. track max sum so far to later by divided by k 
        double result = sum; // initialize to sum for now 
        
        // 4. check all the other possible subarrays now of length k 
        for(int i = k; i < nums.size(); i++)
        {
            // each new element that's added to the window (nums[i])
            // will be having oldest element subtracted (- nums[i - k]) 
            sum += nums[i] - nums[i - k]; 
            result = max(result, sum); 
        }
        
        return result / k; 
    }
};