#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector< vector < int > > result;
		int front,last;
		int lenNum = num.size();
		sort(num.begin(), num.end());
		for (int i = 0; i < lenNum; i ++) {
			if (i != 0 && num[i] == num[i-1]) { 
			       continue; 
			}
			front = i + 1;
			last = lenNum - 1;
			while(front < last) {
				if(num.at(i) + num.at(front) + num.at(last) == 0) {
					int array[] = {num.at(i), num.at(front), num.at(last)};
					vector<int> item(array, array + 3);
					sort(item.begin(), item.end());
					result.push_back(item);
					front ++;
					last --;
					while(front < last && num.at(front) == num.at(front - 1)) {
						front ++;
					}
					while(front < last &&num.at(last) == num.at(last + 1)) {
						last --;
					}
				} else if(num.at(i) + num.at(front) + num.at(last) < 0) {
					front ++;
				} else {
					last --;
				}
			}
		}
		return result;
    }
};

int main() {
	int myarray[] = {0, 0, 0};  
		vector<int> myvector(myarray , myarray+3); 
		vector<vector<int> > result;
		Solution *solution = new Solution();
		result = solution -> threeSum(myvector);
		printf("len == %lu\n", result.size());
		for(int i = 0; i < result.size(); i ++) {
			vector < int > item = result[i];
			printf("%d %d %d\n", item.at(0), item.at(1), item.at(2));
		}
		return 0;
}