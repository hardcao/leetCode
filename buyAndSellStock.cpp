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
        int *minPrices = new int(lenPrices);
		int *maxPrices = new int(lenPrices);
		int result = 0;
		minPrices[0] = prices.at(0);
		maxPrices[0] = prices.at(0);
		for(int i = 1;i < lenPrices; i++) {
			int priceItem = prices.at(i);
			minPrices[i] = getMinNumber(priceItem, minPrices[i-1]);
			maxPrices[i] = getMaxNumber(priceItem, maxPrices[i-1]);
		}
		for(int i = 1;i < lenPrices; i++) {
			result = getMaxNumber(maxPrices[i] - minPrices[i], result);
		}
		delete minPrices;
		delete maxPrices;
		return result;
    }
};

int main()
{
	vector<int> myvector (10);
	for (unsigned i=0; i<myvector.size(); i++) {
	    myvector.at(i)=i;
	}
	Solution *solution = new Solution();
	printf("result == %d\n", solution ->maxProfit(myvector));
	return 0;
}