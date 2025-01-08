#include <stdio.h>
#include <stdlib.h>
/* #define NULL 0 */
struct ListNode {
	int val;
	struct ListNode *next;
};

/**
	 Was having trouble deciding whether to initialise the sum header at the beginning or end of each loop.
	 Beginning felt more elegant as it meant I wouldn't have to go back and NULL the next pointer once finished iterating.
	 As malloc returns a new pointer I would have had to go back to fix the next pointer regardless, so decided on the end.
	 The additional while loops for checking remaining nodes in l1, l2 and the carry value could be rolled up into one in the future.
**/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* sum = malloc(sizeof (struct ListNode));
	struct ListNode* sum_root = sum;
	struct ListNode* prev_sum;
	int carry = 0;
	while (l1 && l2) {
		//printf("l1:%d\n", l1->val);
		//printf("l2:%d\n", l2->val);
		int tmp_sum = (l1->val + l2->val + carry);
		sum->val = tmp_sum%10;
		carry = tmp_sum/10;
        printf("sum: %d\n", sum->val);
		l1 = l1->next;
		l2 = l2->next;
		prev_sum = sum;
		sum->next = malloc(sizeof (struct ListNode));
		sum = sum->next;
	}
	while (l1)
	{
		int tmp_sum = (l1->val + carry);
		sum->val = tmp_sum%10;
		carry = tmp_sum/10;
        printf("sum: %d\n", sum->val);
		l1 = l1->next;
		prev_sum = sum;
		sum->next = malloc(sizeof (struct ListNode));
		sum = sum->next;
	}
	while (l2)
	{
		int tmp_sum = (l2->val + carry);
		sum->val = tmp_sum%10;
		carry = tmp_sum/10;
        printf("sum: %d\n", sum->val);
		l2 = l2->next;
		prev_sum = sum;
		sum->next = malloc(sizeof (struct ListNode));
		sum = sum->next;
	}
	if (carry>0)
	{
		sum->val = carry;
		prev_sum = sum;
	}
	prev_sum->next = NULL;
	return sum_root;
}


int main() {
	struct ListNode l1_3 = {3, NULL};
	struct ListNode l1_2 = {4, &l1_3};
	struct ListNode l1_1 = {2, &l1_2};
	
	struct ListNode l2_3 = {4, NULL};
	struct ListNode l2_2 = {6, &l2_3};
	struct ListNode l2_1 = {5, &l2_2};

	struct ListNode* ret = addTwoNumbers(&l1_1, &l2_1);
	while (ret)
	{
		printf("%d\n", ret->val);
		ret = ret->next;
	}
	return 0;
}
