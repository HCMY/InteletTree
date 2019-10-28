

/**

n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of passengers will:

Take their own seat if it is still available, 
Pick other seats randomly when they find their seat occupied 
What is the probability that the n-th person can get his own seat?

 

Example 1:

Input: n = 1
Output: 1.00000
Explanation: The first person can only get the first seat.
Example 2:

Input: n = 2
Output: 0.50000
Explanation: The second person has a probability of 0.5 to get the second seat (when first person gets the first seat).

**/

/**
solution:
n=1, p=1
n=2 p = 1/2;
n=3 p = (1 picked+2 picked) = (1+1/2)/3
n=4 p = (1 picked+2 picked 3 picked) = (1+1/2+1/2)/2 = 1/2
**/


#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
		if(n==1) return 1;

		vector<double> dp(n,0);
		dp[0] = 1.0;
		double pred_prob = 0;

		for(int i=1; i<n;i++){
			dp[i] = (pred_prob+dp[i-1])/(i+1);
			pred_prob += dp[i-1];
		}

		return dp[n-1];
    }
};


int main(int argc, char const *argv[])
{
	Solution solu;
	cout<<solu.nthPersonGetsNthSeat(1)<<endl;
	cout<<solu.nthPersonGetsNthSeat(2)<<endl;
	cout<<solu.nthPersonGetsNthSeat(3)<<endl;
	return 0;
}