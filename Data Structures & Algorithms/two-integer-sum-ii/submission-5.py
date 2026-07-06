class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = len(numbers)
        left = 0
        right = l - 1
        while left < right:
            s = numbers[left] + numbers[right]
            if s > target:
                right -= 1
            elif s < target:
                left += 1
            else:
                return [left + 1, right + 1]