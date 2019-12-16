/**
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
  		int len =  A.size();
  		int res = 0;
  		vector<int> dp(len,0);
  		if(len<3)
  			return 0;
  		
  		for(int i=2;i<len;i++){
  			if((A[i]-A[i-1]) == (A[i-1]-A[i-2]))
  				dp[i] = dp[i-1]+1;
  			res += dp[i];
  		}

  		return res;

    }
};

int main(int argc, char const *argv[])
{
	Solution solu;

	vector<int> arr1 = {1,2,3,4};
	vector<int> arr2 = {1,3,5,7,9};
	vector<int> arr3 = {7,7,7,7};
	vector<int> arr4 = {1,1,2,5,7};
	
	cout<<solu.numberOfArithmeticSlices(arr1)<<endl;
	cout<<solu.numberOfArithmeticSlices(arr2)<<endl;
	cout<<solu.numberOfArithmeticSlices(arr3)<<endl;
	cout<<solu.numberOfArithmeticSlices(arr4)<<endl;

	return 0;
}