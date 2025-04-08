#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
	 Initial working solution.
	 Still not fantastic with linked list intuition.
 **/

ListNode* deleteDuplicates(ListNode* head) {
	if (!head)
		return head;
	ListNode* root = head;
	ListNode* curr = root;
	ListNode* tmp = curr->next;
	curr->next = nullptr;
	while (tmp) {
		cout << "tmp:" << tmp->val << " curr:" << curr->val << endl;
		if (tmp->val != curr->val) {
			cout << "app" << endl;
			curr->next = tmp;
			curr = curr->next;
		}
  	tmp = tmp->next;
	}
	curr->next = nullptr;
	return root;
}
