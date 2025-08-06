/*
 * Problem: You are given an integer array prices where prices[i] is the price of a given stock on the i-th day.
 * On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it and then immediately sell it on the same day.
 * Find and return the maximum profit you can achieve.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מחירי מניות, מצא את הרווח המקסימלי שניתן להשיג
 * 
 * Example:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 7
 * 
 * Input: prices = [1,2,3,4,5]
 * Output: 4
 * 
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * 
 * Explanation:
 * For the input prices = [7,1,5,3,6,4], the maximum profit can be achieved by buying on day 2 (price = 1) and selling on day 3 (price = 5), and then buying on day 4 (price = 3) and selling on day 5 (price = 6), for a total profit of 5-1 + 6-3 = 7.
 * For the input prices = [1,2,3,4,5], the maximum profit can be achieved by buying on day 1 and selling on day 5, for a total profit of 5-1 = 4.
 * For the input prices = [7,6,4,3,1], no transactions are done, and the maximum profit is 0.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include "Question.h"

int  max_profit(ARR  *  prices)  
{
    if(prices->total_size==0)
        return 0;
        
    int maxProfit=0, minTake=prices->data[0];
    
    for(int i=1; i<prices->total_size; i++)
    {
        if(prices->data[i]>minTake)
        {
            maxProfit+=(prices->data[i]-minTake);
            minTake=prices->data[i];
        }
        
        if(prices->data[i]<minTake)
            minTake=prices->data[i];
    }
    
    return maxProfit;  
}
