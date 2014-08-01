#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
struct ListNodeRate {
     int val;
     ListNodeRate *nextLeft;
	 ListNodeRate *nextRight;
     ListNodeRate(int x) : val(x), nextLeft(NULL), nextRight(NULL){}
};

class Solution {
public:
    int candy(vector<int> &ratings) {
		int result = 0;
		int step = 1;
		int numberOfChildred = ratings.size();
        int *penetration = new int[numberOfChildred];
		int *queFrontNode = new int[numberOfChildred];
		int *queLastNode = new int[numberOfChildred];
		int frontCnt = 0;
		int lastCnt = 0;
		ListNodeRate *listNode[numberOfChildred];
		
		for(int i = 0; i < numberOfChildred; i++) {
			penetration[i] = 0;
			listNode[i] = new ListNodeRate(ratings.at(i));
		}
		for(int i = 0; i < numberOfChildred - 1; i++) {
			if(ratings.at(i) < ratings.at(i + 1)) {
				penetration[i + 1] ++;
				listNode[i]->nextRight = listNode[i+1];
			} else if(ratings.at(i) > ratings.at(i + 1)) {
				penetration[i] ++;
				listNode[i + 1]->nextLeft = listNode[i];
			}
		}
		for(int i = 0; i < numberOfChildred; i ++) {
			if(penetration[i] == 0) {
				result += step;
				queFrontNode[frontCnt ++] = i;
			}
		}
		while(frontCnt) {
			lastCnt = 0;
			step ++;
			for(int i = 0; i < frontCnt; i++) {
				int index = queFrontNode[i];
				if(listNode[index]->nextLeft) {
					penetration[index - 1] --;
					if(penetration[index - 1] == 0) {
						queLastNode[lastCnt ++] = index - 1;
						result += step;
					}
				}
				if(listNode[index]->nextRight) {
					penetration[index + 1] --;
					if(penetration[index + 1] == 0) {
						queLastNode[lastCnt ++] = index +1;
						result += step;
					}
				} 
			}
			printf("lastCnt == %d\n", lastCnt);
			frontCnt = lastCnt;
			for(int i = 0; i < frontCnt; i ++) {
				queFrontNode[i] = queLastNode[i];
			}
		}
		delete penetration;
		delete queFrontNode;
		delete queLastNode;
		return result;
    }
};

int main() {
	int myarray[2] = {2,2};  
	vector<int> myvector(myarray , myarray+2); 
	Solution *solution = new Solution();
	printf("result == %d\n", solution ->candy(myvector));
	return 0;
}