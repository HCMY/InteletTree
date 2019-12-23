/**
Given a string s, find the longest palindromic subsequence's length in s. 
You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
**/



#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int LPS(string original, string reversed){ 
    int m = original.length(), n = reversed.length(); 
    int dp[m+1][n+1]; 

    for (int i = 0; i <= m; i++) 
    { 
        for (int j = 0; j <= n; j++) 
        { 
            if (i == 0 || j == 0) 
                dp[i][j] = 0; 
            else if (original[i-1] == reversed[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1; 
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        } 
    }

    return dp[m][n];
} 


class Solution {
public:
    int longestPalindromeSubseq(string s) {
    	string reversed = s;
        std::reverse(reversed.begin(), reversed.end());
        int max_len = LPS(s,reversed);
        return max_len;  
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	string s1 = "bbbab";
	string s2 = "bccb";
	string s3 = "cbbd";

	cout<<solu.longestPalindromeSubseq(s1)<<endl;
	cout<<solu.longestPalindromeSubseq(s2)<<endl;
	cout<<solu.longestPalindromeSubseq(s3)<<endl;
	
	return 0;
}