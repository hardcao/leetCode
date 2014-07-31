#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int one = 0;
		int two = 0;
		int three = 0;
		for(int i=0;i<n;i++) {
			two |= one&A[i];  
			one^=A[i];  
			three=one&two;  
			one&= ~three;  
			two&= ~three;
		}
		return firstTime;
    }
};

int main()
{
	Solution *test = new Solution();
	int tt[] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
	printf("%d\n",test->singleNumber(tt,10));
	return 0;
}