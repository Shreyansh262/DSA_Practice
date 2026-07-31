class Solution(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        arr = [0]*26
        for c in word:
            arr[ord(c) - ord("a")] += 1
        arr.sort(reverse = True)
        num = 0
        ct = 1
        ans = 0

        for i in arr:
            if i == 0:
                continue 
            num += 1
            if num > 8:
                ct += 1
                num = 1
            ans += i * ct

        return ans
        