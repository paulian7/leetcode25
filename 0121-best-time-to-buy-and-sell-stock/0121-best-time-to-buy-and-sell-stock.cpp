class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // ?: buy low, sell high --> want to get largest profit! 

        // tech: 2 pointers --> time comp: o(n) 
            // will scan through array once 
            // leftPtr - day we buy 
            // rightPtr - day we sell 
        
        // 1. initialize 2 pointers 
        int leftPtr = 0; // buy 
        int rightPtr = 1; // sell 

        int maxProfit = 0; // val to return at the end 

        // 2. iterate thr our array prices 
        while(rightPtr < prices.size())
        {
            // check if we made any profit 
            if(prices[leftPtr] < prices[rightPtr])
            {
                // profit calc (sellPrice - buyPrice)
                int diff = prices[rightPtr] - prices[leftPtr]; 

                // update maxProfit var accordingly 
                maxProfit = max(diff, maxProfit); 
            }
            else 
            {
                // want to update leftPtr bc we found lowest price in rightPtr 
                leftPtr = rightPtr; 
            }

            // always want to update rightPtr as we iterate thr 
            rightPtr++; 
        }

        return maxProfit; 
    }
};