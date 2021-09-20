def findMinDiff(self, A,N,M):
        if N<M:
            return 0
        if N==0 or M==0:
            return 0
        
        A.sort()
        i = 0
        mx = sys.maxsize
        while i+M<=N:
            mx = min(mx, A[i+M-1] - A[i])
            i+=1
        return mx