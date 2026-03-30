class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int p = 0;
        int minTracked = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {   
            p = (prices[i] - minTracked > p) ? prices[i] - minTracked : p;

            if (prices[i] < minTracked)
            {
                minTracked = prices[i];
            }                      
        }
        
        return p;

    }
};
