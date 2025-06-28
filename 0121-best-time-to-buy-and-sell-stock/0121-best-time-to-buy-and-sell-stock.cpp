class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // given an array 
        // want to get biggest difference 
            // but can't sort the array 
        // each value represents the price 

        // must buy first.. then sell afterwards in the future 

        // 2 pointers 
        int buyPtr = 0; 
        int maxProfit = 0; 

        // iterate thr array 
        for(int rightPtr = 1; rightPtr < prices.size(); rightPtr++)
        {
            if(prices[rightPtr] > prices[buyPtr])
            {
                int diff = prices[rightPtr] - prices[buyPtr]; 

                maxProfit = max(maxProfit, diff); 
            }
            else 
            {
                // leftPtr is actually bigger than rightPtr's value 
                // want to swap! 
                buyPtr = rightPtr; 
            }
        }

        return maxProfit; 
    }
};