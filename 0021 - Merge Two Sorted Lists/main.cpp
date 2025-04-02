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
	 Obvious solution.
	 Took longer than it should have, need more practice on linked list intuition.
	 Visualisation is harder than it should be.
 **/

void print_ll(ListNode *list) {
  while (list) {
    cout << list->val << " ";
    list = list->next;
  }
  cout << endl;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode root;
  ListNode *curr;
  curr = &root;

  cout << "l1 ";
  print_ll(list1);
  cout << "l2 ";
  print_ll(list2);

  while (list1 && list2) {
    if (list1->val <= list2->val) {
      curr->next = list1;
      list1 = list1->next;
    } else {
      curr->next = list2;
      list2 = list2->next;
    }
		curr = curr->next;
  }
	curr->next = list1 ? list1 : list2;
  return root.next;
}

int main() {
  ListNode l3 = ListNode(4);
  ListNode l2 = ListNode(2, &l3);
  ListNode l1 = ListNode(1, &l2);

  ListNode r3 = ListNode(4);
  ListNode r2 = ListNode(3, &r3);
  ListNode r1 = ListNode(1, &r2);

  print_ll(mergeTwoLists(&l1, &r1));
  return 0;
}
