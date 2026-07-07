class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)
        max_l, max_r = 0, 0
        l, r = 0, length - 1
        total = 0

        while l < r:
            # if current left is shorter than max left, we add difference in height
            # if curr left is higher, we reset max left

            # between the left max and right max, only consider the smaller one.
            # If we consider larger of the two, theres no guarantee it has a matching wall
            l_h, r_h = height[l], height[r]
            if l_h < r_h:
                if l_h >= max_l:
                    max_l = l_h
                else:
                    total += max_l - l_h
                l += 1
            else:
                if r_h >= max_r:
                    max_r = r_h
                else:
                    total += max_r - r_h
                r -= 1
        return total
