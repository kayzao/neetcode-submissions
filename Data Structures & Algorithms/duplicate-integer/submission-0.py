class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # use a hashset to keep track of duplictes
        seen = set()

        for i in nums:
            if i in seen:
                return True
            seen.add(i)
        return False