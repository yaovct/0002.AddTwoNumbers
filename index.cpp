#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
		int val;
		ListNode *next = NULL;
		ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	ListNode *p = l1;
    	ListNode *q = l2;
    	ListNode *h;
    	ListNode *l3;
    	h = l3 = new ListNode((p->val + q->val)%10);
    	int carry = (p->val + q->val)/10;
    	p = p->next;
    	q = q->next;
    	while(p != NULL || q != NULL) {
    		if(p != NULL && q != NULL) {
    			h->next = new ListNode((p->val + q->val + carry)%10);
    			carry = (p->val + q->val + carry)/10;
    			h = h->next;
    			p = p->next;
    			q = q->next;
    		} else if(p != NULL) {
    			h->next = new ListNode((p->val + carry)%10);
    			carry = (p->val + carry)/10;
    			h = h->next;
    			p = p->next;
    		} else {
    			h->next = new ListNode((q->val + carry)%10);
    			carry = (q->val + carry)/10;
    			h = h->next;
    			q = q->next;
    		}
    	}
    	if(carry > 0) {
    		h->next = new ListNode(carry);
    	}
    	return l3;
    }
};

void printList(ListNode *ll) {
	ListNode *p = ll;
	cout << "[";
	while(p->next != NULL) {
		cout << p->val << ",";
		p = p->next;
	}
	cout << p->val << "]" << endl;
}

int main(int argc, char *argv[]) {
	int i1[3] = {2, 4, 5};
	int i2[3] = {3, 6, 4};
	ListNode *l1 = new ListNode(2);
	ListNode *p = l1;
	for(int i=0; i<sizeof(i1)/sizeof(int); i++) {
		p->next = new ListNode(i1[i]);
		p = p->next;
	}
	ListNode *l2 = new ListNode(3);
	ListNode *q = l2;
	for(int i=0; i<sizeof(i2)/sizeof(int); i++) {
		q->next = new ListNode(i2[i]);
		q = q->next;
	}
	printList(l1);
	printList(l2);

	Solution mySolution;
	ListNode *l3;
	l3 = mySolution.addTwoNumbers(l1, l2);
	printList(l3);
	
}