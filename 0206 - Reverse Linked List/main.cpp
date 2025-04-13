using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
	 Initial recursive solution.
	 Not very tricky, but again overthinking it.
	 I always try to think of an optimal solution first, rather than just getting something down.
	 Was trying to think of a recursive solution with the initial function signature.
	 Don't think it's possible without the previous node variable.
 **/

ListNode* reverseListRecursive(ListNode* head, ListNode* prev) {
	if (!head)
		return prev;
	ListNode* tmp = head->next;
	head->next = prev;
	return reverseListRecursive(tmp, head);
}

ListNode* reverseList(ListNode* head) {
	return reverseListRecursive(head, nullptr);
}


int main() {
	return 0;
}
