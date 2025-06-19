class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // ?: buy low, sell high --> want to get the largest profit

        // tech: 2 pointers --> time comp: o(n) 
            // will scan thr array once 
            // leftPtr - the day we buy 
            // rightPtr - the day we sell 
        
        // 1. initialize 2 pointers 
        int leftPtr = 0; 
        int rightPtr = 1; 

        // val to return at end 
        int maxProfit = 0; 

        // 2. iterate thr our array prices 
        while(rightPtr < prices.size())
        {
            // check if we've made any profit   
                // if left < right 
            if(prices[leftPtr] < prices[rightPtr])
            {
                // profit calc (sellfPrice - buyPrice)
                int diff = prices[rightPtr] - prices[leftPtr]; 

                // update maxProfit variable accordingly 
                maxProfit = max(maxProfit, diff); 
            }
            else 
            {
                // want to update leftPtr bc we found an EVEN...
                    // ... lower price in rightPtr 
                leftPtr = rightPtr; 
            }

            // always want to update rightPtr as we itterate through 
            rightPtr++; 
        }

        return maxProfit; 
    }
};