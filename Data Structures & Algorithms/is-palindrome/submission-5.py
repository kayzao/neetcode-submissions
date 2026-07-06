class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0

        fs = "".join(c.lower() for c in s if c.isascii() and c.isalnum());
        back = len(fs) - 1
        while back > i:
            if fs[i] != fs[back]:
                return False
            i += 1
            back -= 1
        return True