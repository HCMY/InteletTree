

/**
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
			return a[1] < b[1];
		}


class Solution {
public:

	
    int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(),pairs.end(),cmp);

        int len = pairs.size();
        int res = 0;
        
        if(len<2)
        	return res+1;

        vector<int> dp(len,1);
        for(int i=1;i<len;i++){
        	for(int j=0;j<i;j++){
        		if(pairs[i][0]>pairs[j][1])
        			dp[i] = max(dp[i],dp[j]+1);
        	}
        	res = max(res,dp[i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	vector<vector<int>> arr = {{3,4},{1,2},{2,3}};
	vector<vector<int>> arr2 = {{9,10},{9,10},{4,5},{-9,-3},{-9,1},{0,3},{6,10},{-5,-4},{-7,-6}};
	cout<<solu.findLongestChain(arr)<<endl;
	cout<<solu.findLongestChain(arr2)<<endl;
	return 0;
}