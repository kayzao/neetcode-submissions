class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        l = len(s)
        back = l - 1
        while back > i:
            while i < l and not (s[i].isascii() and s[i].isalnum()):
                i += 1
            while back >= 0 and not ( s[back].isascii() and s[back].isalnum()):
                back -= 1
            if back <= i:
                return True
            print(s[i], s[back])
            if s[i].lower() != s[back].lower():
                return False
            i += 1
            back -= 1
        return True