class Solution:
    def longestPalindrome(self, s: str) -> str:
        self.s = s
        if s[::-1]==s:
            print(len(s))
            return 0
        ans = ""
        for y in range(0,len(s)):
            for x in range(y+1,len(s)+1):
                try:
                    temp = s[y:x]
                    if temp[::-1]==temp and len(temp)>len(ans):
                        ans = temp
                except IndexError:
                    pass
                if len(ans)==len(s):
                    print(len(ans))
                    return 0
        print(len(ans))
        return 0
a=Solution().longestPalindrome
a(input())