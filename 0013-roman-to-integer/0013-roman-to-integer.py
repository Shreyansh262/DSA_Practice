class Solution:
    def romanToInt(self, s: str) -> int:
        dirr = {'I': 1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        a  = len(s)
        i = 0
        num = 0
        while i < a-1:
            b = s[i]
            c = s[i+1]
            if dirr[b] < dirr[c]:
                num += dirr[c] - dirr[b]
                i+=1
            else:
                 num += dirr[b]
            i+=1
        if i != a:
            num += dirr[s[i]]
        return num
            