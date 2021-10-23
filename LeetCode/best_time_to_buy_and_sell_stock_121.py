# You are given an array prices where prices[i] is the price of a given stock on the ith day.
# You want to maximize your profit by choosing a single day to buy one stock and choosing a
# different day in the future to sell that stock.
# Return the maximum profit you can achieve from this transaction.
# If you cannot achieve any profit, return 0.


# O(n^2 Time Complexity)
# def max_profit(prices):
#     maximum = 0
#     for left in range(len(prices)):
#         for right in range(len(prices)-1, 0, -1):
#             if right > left:
#                 profit = prices[right] - prices[left]
#                 print(profit, prices[left], prices[right])
#             if profit > maximum:
#                 maximum = profit
#     return maximum


# print(max_profit([7,6,4,3,1]))


def max_profit(prices):
    max_value_right = prices[-1]
    maximum_profit = 0

    for i in prices[::-1]:
        if i < max_value_right:
            maximum_profit = max(maximum_profit, max_value_right-i)
        else:
            max_value_right = i
    
    return maximum_profit

    
print(max_profit([7,1,5,3,6,4]))