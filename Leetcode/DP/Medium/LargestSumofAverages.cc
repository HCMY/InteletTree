/**
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input: 
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation: 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  double largestSumOfAverages(vector<int>& A, int K) {
    int len = A.size();
    vector<vector<double>> dp(K, vector<double>(len, 0.0));
    vector<double> sums(len, 0.0);
    sums[0] = A[0];
    dp[0][0] = A[0];

    for (int i = 1; i <len; i++) {
      sums[i] = sums[i - 1] + A[i];
      dp[0][i] = (sums[i])/(i+1);
    }
    
    for (int k = 1; k < K; ++k)
      for (int i = k; i <len; ++i)
        for (int j = k - 1; j < i; ++j)
          dp[k][i] = max(dp[k][i], dp[k - 1][j] + (sums[i] - sums[j]) / (i - j));
    
    return dp[K-1][len-1];
  }
};


int main(int argc, char const *argv[])
{
	Solution solu;
	vector<int> arr = {9,1,2,3,9};
	vector<int> arr2 = {8822,2355,6002,5176,8185,807,6152,4962,4402,5925};
	cout<<solu.largestSumOfAverages(arr,3)<<endl;
	cout<<solu.largestSumOfAverages(arr2,7)<<endl;
	return 0;
}