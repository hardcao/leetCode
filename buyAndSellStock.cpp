#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int getMinNumber(int a,int b) {
		return a<b?a:b;
	}
	int getMaxNumber(int a,int b) {
		return a>b?a:b;
	}
    int maxProfit(vector<int> &prices) {
		int lenPrices = prices.size();
		if(lenPrices == 0) return 0;
 	   	int minPrice = prices.at(0),maxPrice = prices.at(lenPrices-1);
		int result = 0,maxProfit = 0;
		vector<int> *firstProfit = new vector<int>(lenPrices);
		firstProfit -> at(0) = 0;
		for(int i = 1;i < lenPrices; i++) {
			int currentPrice = prices.at(i);
			printf("%d ", currentPrice);
			result = getMaxNumber(currentPrice - minPrice, result);
			minPrice = getMinNumber(minPrice, currentPrice);
			firstProfit -> at(i) = result; 
		}
		maxProfit = result;
		for(int i=0;i<lenPrices;i++) {
			printf("%d ", firstProfit -> at(i));
		}
		printf("\n");
		result = 0;
		for(int i = lenPrices -2;i > 0; i--) { 
			int currentPrice = prices.at(i);
			result = getMaxNumber(maxPrice - currentPrice, result);
			maxPrice = getMaxNumber(maxPrice, currentPrice);
			maxProfit = getMaxNumber(maxProfit,result + firstProfit -> at(i-1));
			printf("maxProfit == %d", maxProfit);
		}
		cout<<endl;
		return maxProfit;
    }
};

int main()
{
	int myarray[5] = {2,1,2,0,1};  
	vector<int> myvector(myarray , myarray+5); 
	Solution *solution = new Solution();
	printf("result == %d\n", solution ->maxProfit(myvector));
	return 0;
}