class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = set()
        q = deque()
        best = 0
        # curr_len = 0
        for i in range(len(s)):
            # print(s[i], q)
            if s[i] in seen:
                while q[0] != s[i]:
                    seen.remove(q[0])
                    q.popleft()
                q.popleft()
            else:
                seen.add(s[i])
            q.append(s[i])
            best = max(best, len(q))
        return best