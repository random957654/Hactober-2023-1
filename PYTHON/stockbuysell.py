# Stock Buy Sell to Maximize Profit

# The cost of a stock on each day is given in an array. Find the maximum profit that you can make by buying and selling on those days. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.

# Examples:

# Input: arr[] = {100, 180, 260, 310, 40, 535, 695} Output: 865 Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210 Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655 Maximum Profit = 210 + 655 = 865

 
def maxProfit(price, start, end):
 
    # If the stocks can't be bought
    if (end <= start):
        return 0
 
    # Initialise the profit
    profit = 0
 
    # The day at which the stock
    # must be bought
    for i in range(start, end, 1):
        #print("ith time",i)
        # The day at which the
        # stock must be sold
        for j in range(i+1, end+1):
            #print("jth time ",j)
            # If buying the stock at ith day and
            # selling it at jth day is profitable
            if (price[j] > price[i]):
 
                # Update the current profit
                curr_profit = price[j] - price[i] +\
                    maxProfit(price, start, i - 1) + \
                    maxProfit(price, j + 1, end)
                #print(curr_profit,"current profit is","j=",j,price[j],"i=",i, price[i],"maxProfit(price, start, i - 1)",maxProfit(price, start, i - 1),start, i-1,"maxProfit(price,j+1,end)",maxProfit(price, j + 1, end), j+1,end,price )
 
                # Update the maximum profit so far
                profit = max(profit, curr_profit)
                #print("profit",profit)
 
    return profit
 
 
# Driver code
if __name__ == '__main__':
    price = [4,2,2,2,4]
    n = len(price)
# output is 2
 
    print(maxProfit(price, 0, n - 1))
