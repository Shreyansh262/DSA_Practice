class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        a = ""
        j = len(strs)
        l = 0
        b = ""
        for _ in range(len(strs[0]  )):
            j = 0
            a = strs[0][0:_+1]
            for st in strs:
                if a == st[0:_+1]:
                    j+=1
            if j == len(strs):
                    b = a
            else:
                    return b

        return b