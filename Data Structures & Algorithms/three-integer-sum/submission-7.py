class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sort = sorted(nums)
        ans = []
        # print(sort)

        for i in range(len(sort) - 2):
            if i > 0 and sort[i] == sort[i - 1]:
                continue
            l = i + 1
            r = len(sort) - 1
            while r > l:
                s = sort[l] + sort[r]
                target = -sort[i]
                if s == target:
                    to_add = [sort[i], sort[l], sort[r]]
                    ans.append(to_add)
                    l += 1
                    while l < r and sort[l] == sort[l - 1]:
                        l += 1
                    
                    # while r > l and sort[r] == sort[r - 1]:
                    #     r -= 1
                    continue
                if s < target:
                    l += 1
                else:
                    r -= 1
        return ans