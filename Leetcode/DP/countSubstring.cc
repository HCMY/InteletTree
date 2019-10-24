#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
**/

class Solution {
public:
    int countSubstrings(string s) {
		vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
		int str_len = s.length()-1;
		int count = 0;

		for(int i=str_len;i>=0;i--){
			for(int j=i;j<=str_len;j++){
				dp[i][j] = (s[i]==s[j]) && (j-i<=2 || dp[i+1][j-1]);
				if(dp[i][j])
					count++;
			}
		}

		return count;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	string s = "abc";
	cout<<solu.countSubstrings(s)<<endl;
	return 0;
}