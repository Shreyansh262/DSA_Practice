class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        a = len(board)
        s = 0
        c = [[] for _ in range(9)]
        r = [[] for _ in range(9)]
        k = 0
        if a != 9:
            return False
        for h,i in enumerate(board):
            if len(i) != 9:
                return False
            for w,j in enumerate(i):
                c[w].append(j)
                s =( h//3) *3
                r[w//3 + int(s)].append(j)
           
        if self.check(board):
            k = k + 1
        if self.check(c):
            k = k + 1
        if self.check(r):
            k = k + 1
        if  k == 3:
            return True
        else:
            return False
        
    def check(self, board: List[List[str]]) -> bool:
        for i in (board):
            if len(i)!=9:
                return False
            m = i.count(".")
            x = set(i)
            if 9 != (len(x) + m -1):
                return False
        return True
        
        