class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [] 
        for i in range(m):          # 申请一个m*n的矩阵，并将值初始化为1
            dp.append([1]*n)

        for i in range(1, m):         # 从1开始遍历，得到每一个位置的路径树
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        return dp[m-1][n-1]       # 最终结果

if __name__ == '__main__':
	solu = Solution();
	print(solu.uniquePaths(3,2))
	print(solu.uniquePaths(23,12))