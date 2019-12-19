
/**
Given an array A of integers, return the length of the longest arithmetic subsequence in A.

Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

Example 1:

Input: [3,6,9,12]
Output: 4
Explanation: 
The whole array is an arithmetic sequence with steps of length = 3.
Example 2:

Input: [9,4,7,2,10]
Output: 3
Explanation: 
The longest arithmetic subsequence is [4,7,10].
Example 3:

Input: [20,1,15,3,10,5,8]
Output: 4
Explanation: 
The longest arithmetic subsequence is [20,15,10,5].

*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int len = A.size();
        int res = 0;

        if(A.size()<2)
        	return res;
        //vector<map<int,int>> dp(len);
        unordered_map<int, unordered_map<int, int>>dp;
        for(int i=1;i<len;i++){
        	for(int j=0;j<i;j++){
        		int gap = A[i]-A[j];

        		if(!dp[j][gap]){
        			dp[i][gap] = 2;
        		}
        		else{
        			dp[i][gap] = dp[j][gap]+1;
        		}
        		
        		res = max(res,dp[i][gap]);
        	}
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	std::vector<int> v3={20,1,15,3,10,5,8};
	std::vector<int> v1={3,6,9,12};
	std::vector<int> v2={9,4,7,2,10};
	std::vector<int> v4={24,13,1,100,0,94,3,0,3};

	cout<<solu.longestArithSeqLength(v3)<<endl;
	cout<<solu.longestArithSeqLength(v1)<<endl;
	cout<<solu.longestArithSeqLength(v2)<<endl;
	cout<<solu.longestArithSeqLength(v4)<<endl;

	return 0;
}