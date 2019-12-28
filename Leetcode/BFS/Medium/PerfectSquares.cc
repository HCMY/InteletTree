/**
Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
		int tmp = int(sqrt(n));
		vector<int> square_element;
		queue<int> square_queue;
		int level = 1;
		
		if(n<1)
			return 0;

		for(int i=1;i<=tmp;i++)
			square_element.push_back(i*i);
		for(auto item:square_element)
			square_queue.push(item);
		square_queue.push(-1);

		while(!square_queue.empty()){
			while(square_queue.front()!=-1){
				tmp = square_queue.front();
				if(tmp==n)
					return level;
				for(auto item:square_element)
					square_queue.push(item+tmp);
				square_queue.pop();
			}
			square_queue.pop();
			square_queue.push(-1);
			level++;
		}

		return -1;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	cout<<solu.numSquares(12)<<endl;
	cout<<solu.numSquares(13)<<endl;
	cout<<solu.numSquares(1)<<endl;
	
	return 0;
}