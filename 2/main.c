#include <stdio.h>
#define NULL 0
struct ListNode {
	int val;
	struct ListNode *next;
};

void addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	while (l1 && l2) {
		printf("l1:%d\n", l1->val);
		printf("l2:%d\n", l2->val);
		l1 = l1->next;
		l2 = l2->next;
	}
}

int main() {
	struct ListNode l1_3 = {3, NULL};
	struct ListNode l1_2 = {4, &l1_3};
	struct ListNode l1_1 = {2, &l1_2};
	
	struct ListNode l2_3 = {4, NULL};
	struct ListNode l2_2 = {6, &l2_3};
	struct ListNode l2_1 = {5, &l2_2};

	addTwoNumbers(&l1_1, &l2_1);
	return 0;
}
