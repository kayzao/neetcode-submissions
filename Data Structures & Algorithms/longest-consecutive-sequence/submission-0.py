class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # add all nums to set
        # for each num in list, check for existence of prev number, if so add to list of heads
        # once all heads gathered, go thru each one and keep track of longest chain

        s = set(nums)
        heads = set()
        best = 0

        for i in nums:
            if i - 1 not in s:
                heads.add(i)

        for h in heads:
            i = h
            l = 0
            while i in s:
                l += 1
                i += 1
            best = max(best, l)
        
        return best