using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
	 Initial recursive solution, worked first try.
	 Slightly puzzled as to how it did.
	 Seems like the recursive solution should have more edge cases, but I suppose it doesn't.
	 I think I have a tendency to overthink recursive solutions.
	 Just need to do more of them I think.
 **/

ListNode* removeElements(ListNode* head, int val) {
	if (!head)
		return nullptr;
	if (head->val == val) 
		return removeElements(head->next, val);

	head->next = removeElements(head->next, val);
	return head;
}

int main() {
	return 0;
}
