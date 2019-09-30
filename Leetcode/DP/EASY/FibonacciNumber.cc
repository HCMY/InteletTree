/**
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).



Example 1:

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
**/


#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int N) {
		vector<int> v;
		v.push_back(0);//n=0
		v.push_back(1);//n=1
		if(N<=1)
			return v[N];

		for(int i=2;i<=N;i++)
			v.push_back(v[i-1]+v[i-2]);

		return v[v.size()-1];
    }
};



int main(int argc, char const *argv[])
{
	Solution solu;
	cout<<solu.fib(0)<<endl;
	return 0;
}
