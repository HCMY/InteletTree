
/**
Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  

The next row's choice must be in a column that is different from the previous row's column by at most one.
**/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;




class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
    	int rows = A.size();
    	int cols = A[0].size();

		vector<vector<int>> dp(rows+1,vector<int>(cols+2,INT_MAX));
		// padding value
		for(int i=1;i<=rows;i++){
			for(int j=1;j<=cols;j++)
				dp[i][j] = A[i-1][j-1];
		}

		for(int row=2;row<=rows;row++){
			for(int col=1;col<=cols;col++){
				dp[row][col] = dp[row][col]+min({dp[row-1][col-1],dp[row-1][col],dp[row-1][col+1]});
				//cout<<dp[row][col]<<" ";
			}

		}

		int min_val = INT_MAX;
		for(int i=1;i<=cols;i++)
			min_val = min(min_val,dp[rows][i]);

		return min_val;

    }
};


int main(int argc, char const *argv[])
{
	Solution solu;
	vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
	cout<<solu.minFallingPathSum(A)<<endl;
	return 0;
}
