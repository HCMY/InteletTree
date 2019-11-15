/**
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
**/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	vector<int> dp(nums.size(),1);

    	int res = 0;
    	for(int i=0; i<nums.size();i++){
    		for(int j=0; j<i; j++){
    			if(nums[i]>nums[j])
    				dp[i] = max(dp[i],dp[j]+1);
    		}
    		res = max(dp[i],res);
    	}
    	return res;
    }
};


int main(int argc, char const *argv[])
{
	Solution solu;
	vector<int> arr1={10,9,2};
	vector<int> arr2={10,9,2,5,3};
	vector<int> arr3={10,9,2,5,3,7,101,18};

	cout<<solu.lengthOfLIS(arr1)<<endl;
	cout<<solu.lengthOfLIS(arr2)<<endl;
	cout<<solu.lengthOfLIS(arr3)<<endl;

	return 0;
}