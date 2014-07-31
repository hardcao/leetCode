#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *frontPointer = head;
		ListNode *lastPointer = head;
		while(frontPointer != NULL) {
			if(frontPointer) { 
				frontPointer = frontPointer -> next;
			}
			if(lastPointer) {
				lastPointer = lastPointer -> next;
			}
			if(lastPointer) {
				lastPointer = lastPointer -> next;
			}
			if(lastPointer != NULL && lastPointer == frontPointer) {
				frontPointer = head;
				while (frontPointer != lastPointer) {
					lastPointer = lastPointer ->next;
					frontPointer = frontPointer ->next;
				}
				return frontPointer;
			}
		}
		return NULL;
    }
};

int main()
{
	ListNode *nd[10], *head, *result;
	head = new ListNode(1);
	for(int i=0 ;i < 10; i++) {
		nd[i] = new ListNode(i);
	}
	for(int i=0 ;i < 10; i++) {
		nd[i] -> next = nd[(i+1)%10];
	}
	head -> next = nd[0];
	Solution *solution = new Solution();
	result = solution ->detectCycle(head);
	if(result == NULL) printf("result == NULL");
	else  printf("result ==%d %d\n", result -> val, head -> val);
	for(int i=0 ;i < 10; i++) {
		printf("nd == %d\n",nd[i] -> val);
	}
	return 0;
}