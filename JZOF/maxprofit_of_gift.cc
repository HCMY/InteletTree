/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
    	if(grid.size()==0)
    		return 0;
    	
    	int rows = grid.size();
    	int cols = grid[0].size();

    	vector<vector<int>> dp(rows, vector<int>(cols, 0));

    	for(int row=0;row<rows;row++){
    		for(int col=0;col<cols;col++){
    			if(row==0 && col==0)
    				dp[row][col] = grid[row][col];
    			else if(row==0 && col!=0)
    				dp[row][col] = dp[row][col-1] + grid[row][col];
    			else if(row!=0 && col==0)
    				dp[row][col] = dp[row-1][col] + grid[row][col];
    			else
    				dp[row][col] = max(dp[row-1][col], dp[row][col-1]) + grid[row][col];
    		}
    	}

    	return dp[rows-1][cols-1];
    }
};
