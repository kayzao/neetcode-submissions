class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # go thru array backwards and see when the bigest jump exists from currentHigh and current
        curr_max = 0
        ans = 0
        for i in reversed(prices):
            ans = max(ans, curr_max - i)
            curr_max = max(curr_max, i)

        return ans