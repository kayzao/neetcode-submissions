class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if not len(s) == len(t):
            return False
        dict_s = defaultdict(int)
        dict_t = defaultdict(int)
        
        for c in s:
            dict_s[c] = dict_s[c] + 1
        for c in t:
            dict_t[c] = dict_t[c] + 1

        for c in s:
            if not dict_s[c] == dict_t[c]:
                return False

        for c in t:
            if not dict_s[c] == dict_t[c]:
                return False

        return True