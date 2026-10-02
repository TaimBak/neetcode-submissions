class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // There is going to be a window of opprotunity that will start with a low price and end with a high price. This is when you should buy and sell, respectivly. A sliding window over the values looking for the largest delta between values is probably the best solution. How would I brute force this? What is the basic syntax for doing a sliding window in cpp?
        
        // It doesnt care about returning the actual days, just the maximum profit that can be had by utilizing those days.

        // Find the lowest value and then look to the right and find the highest price from the remaining days. Can't buy and then sell in the past. O(n^2)


        // Track the min price seen and then have a second pointer explore the profits using a two pointer system

        int profit = 0;
        int left = 0;

        for (int right = 1; right < prices.size(); right++)
        {
            if (prices[right] > prices[left])
                profit = max(profit, prices[right] - prices[left]);
            else
                left = right;

        }

        return profit;
    }
};
