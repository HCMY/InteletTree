

/**

f(n) = f(n-1)+f(n-2)+...+f(2)+f(1)+1
相当于前n项和公式
之后再加1
是一个典型的类似于斐波那契的数列

*/
#include <iostream>

using namespace std;

/*
class Solution {
public:
    int jumpFloorII(int number) {
    	
    	if(number==0) return 0;
    	if(number==1) return 1;

    	int sum = 1;

    	for(int i=2;i<=number;i++)
    		sum *=2;
    	return sum;
    }
};
*/

class Solution {
public:
    int jumpFloorII(int number) {
    	
    	if(number==0) return 0;
    	if(number==1) return 1;

    	int sum = 1;
    	int pre = 1;
    	for(int i=1;i<number;i++){
    		sum += pre;
    		pre = sum; 
    	}
    	return sum;
    }
};


int main(int argc, char const *argv[])
{
	Solution solu;
	cout<<solu.jumpFloorII(5);
	return 0;
}