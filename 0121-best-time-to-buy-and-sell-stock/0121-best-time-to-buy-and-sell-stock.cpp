class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // array 
        // want to find the largest difference in one pass --> time comp: o(n) 
            // space comp: o(1) 
        
        int leftPtr = 0; // buy 
        int rightPtr = 1; // sell 

        int maxProfit = 0; 

        // iterate thr our input array 
        while(rightPtr < prices.size())
        {
            // if any profit has been made? 
            if(prices[rightPtr] > prices[leftPtr])
            {
                int diff = prices[rightPtr] - prices[leftPtr]; 

                // update our result 
                maxProfit = max(maxProfit, diff); 
            } 
            else 
            {
                leftPtr = rightPtr; 
            }

            rightPtr++; 
        }

        return maxProfit; 
    }
};