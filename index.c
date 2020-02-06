#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode *l3 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode *p = l1;
	struct ListNode *q = l2;
	struct ListNode *h = l3;
	l3->val = (p->val + q->val) % 10;
	l3->next = NULL;
	int carry = (p->val + q->val) / 10;
	p = p->next;
	q = q->next;
	while(p != NULL || q != NULL) {
		if(p != NULL && q != NULL){
			struct ListNode *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
			tmp->val = (p->val + q->val + carry) % 10;
			tmp->next = NULL;
			carry = (p->val + q->val + carry) / 10;
			p = p->next;
			q = q->next;
			h->next = tmp;
			h = h->next;
		} else if(p != NULL) {
			struct ListNode *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
			tmp->val = (p->val + carry) % 10;
			tmp->next = NULL;
			carry = (p->val + carry) / 10;
			p = p->next;
			h->next = tmp;
			h = h->next;
		} else {
			struct ListNode *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
			tmp->val = (q->val + carry) % 10;
			tmp->next = NULL;
			carry = (q->val + carry) / 10;
			q = q->next;
			h->next = tmp;
			h = h->next;
		}
	}
	if(carry > 0) {
		struct ListNode *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
		tmp->val = carry;
		tmp->next = NULL;
		h->next = tmp;
	}
	return l3;
}

void printList(struct ListNode *ll) {
	struct ListNode *p = ll;
	printf("[");
	while(p->next != NULL) {
		printf("%d,",p->val);
		p = p->next;
	}
	printf("%d]\n",p->val);
}

int main(int argc, char *argv[]) {
	int i1[3] = {2, 4, 5};
	int i2[3] = {3, 6, 4};
	struct ListNode *l1 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode *p = l1;
	p->val = i1[0];
	for(int i=1; i<sizeof(i1)/sizeof(int); i++) {
		struct ListNode *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
		tmp->val = i1[i];
		tmp->next = NULL;
		p->next = tmp;
		p = p->next;
	}
	struct ListNode *l2 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode *q = l2;
	q->val = i2[0];
	for(int i=1; i<sizeof(i2)/sizeof(int); i++) {
		struct ListNode *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
		tmp->val = i2[i];
		tmp->next = NULL;
		q->next = tmp;
		q = q->next;
	}
	printList(l1);
	printList(l2);

	struct ListNode *l3 = addTwoNumbers(l1, l2);
	printList(l3);
	
}