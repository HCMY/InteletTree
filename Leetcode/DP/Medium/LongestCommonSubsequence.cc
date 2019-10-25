
/**
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3

*/

// dynamic foumula
/**

dp[i][j] = dp[i-1][j-1], where text2[i]==text1[j]
dp[i][j] = max(dp[i][j-1], dp[i-1][j]),where text2[i]!=text1[j]
other wise, element is zero


**/



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int text1_len = text1.length();
        int text2_len = text2.length();

        vector<vector<int>> dp(text2_len+1, vector<int>(text1_len+1,0));

        for(int i=1;i<=text2_len;i++){
        	for(int j=1;j<=text1_len;j++){
        		if(text1[j-1] == text2[i-1])
        			dp[i][j] = dp[i-1][j-1]+1;
        		else
        			dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        	}
        }

        return dp[text2_len][text1_len];
    }
};


int main(int argc, char const *argv[])
{
	Solution solu;

	string text1 = "abc";
	string text2 = "def";

	cout<<solu.longestCommonSubsequence(text1,text2)<<endl;
	return 0;
}