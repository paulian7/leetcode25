class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // declare result to return @ the end 
        int result = 0; 

        int leftPtr = 0; 
        for(int rightPtr = 1; rightPtr < prices.size(); rightPtr++)
        {
            // check for invalid window?? 
            if(prices[leftPtr] < prices[rightPtr])
            {
                int diff = prices[rightPtr] - prices[leftPtr]; 
                result = max(result, diff);
            }
            else 
            {
                leftPtr = rightPtr;
            }
        }

        return result;
    }
};