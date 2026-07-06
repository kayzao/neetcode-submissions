class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)
        prev_r = length - 1
        prev_l = 0
        r = length - 1
        l = 0
        total = 0
        while r >= l:
            if r < prev_r and height[r] >= height[prev_r]:
                temp = (prev_r - r - 1) * min(height[r], height[prev_r]) - sum(height[r + 1:prev_r])
                total += max(0, temp)
                prev_r = r

            if l > prev_l and height[l] >= height[prev_l]:
                temp = (l - prev_l - 1) * min(height[l], height[prev_l]) - sum(height[prev_l + 1:l])
                total += max(0, temp)
                prev_l = l

            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return total
