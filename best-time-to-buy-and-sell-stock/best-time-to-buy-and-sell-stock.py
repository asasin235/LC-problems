class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i=0
        j=1
        max_profit=0
        n=len(prices)
        while(j<n):
            if(prices[i]>prices[j]):
                i=j
            profit=prices[j]-prices[i]
            max_profit=max(max_profit,profit)
            j+=1
        return max_profit
            