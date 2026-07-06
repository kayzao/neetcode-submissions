class Solution:
    def maxArea(self, heights: List[int]) -> int:
        # two pointer, move it in out to in, keeping track of best result
        l = 0
        r = len(heights) - 1
        best = 0
        while r > l:
            l_h = heights[l]
            r_h = heights[r]
            best = max(best, min(r_h, l_h) * (r - l))
            if l_h > r_h:
                r -= 1
            else:
                l += 1
        return best