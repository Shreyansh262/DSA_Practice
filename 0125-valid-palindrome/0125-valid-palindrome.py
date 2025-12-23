class Solution:
    def isPalindrome(self, s: str) -> bool:
        sn = s.lower()
        sf=""
        sfr=""
        for i in range(len(s)):
            if sn[i].isalpha() or sn[i].isdigit():
                sf = sf + sn[i]
                sfr = sn[i] + sfr

        if (sf == sfr) :
            return True
        else:
            return False
        