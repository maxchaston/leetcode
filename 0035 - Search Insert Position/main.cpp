#include <iostream>
#include <vector>
using namespace std;

/**
         Functional binary search solution.
         A little convoluted though, need to make a cleaner solution for 1
 element.
 **/

void print_vec(vector<int> x, int l, int r) {
  for (; l <= r; l++) {
    cout << x[l] << ' ';
  }
  cout << endl;
}

int searchInsert(vector<int> &nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  while (1) {
  start:
    print_vec(nums, l, r);
    int midpoint = (r + l) / 2;
    int val = nums[midpoint];
    if (val == target)
      return midpoint;
    if (r == l) {
      cout << "a" << endl;
      cout << "val:" << val << endl;
      cout << "target:" << target << endl;
      cout << "r:" << r << endl;
      return r + (val < target ? 1 : 0);
    }
    if (r == l + 1) {
      cout << "b" << endl;
      cout << "val:" << val << endl;
      cout << "target:" << target << endl;
      cout << "r:" << r << endl;
      cout << "l:" << l << endl;
      if (nums[r] > target) {
        r--;
      } else {
        l++;
      }
      goto start;
    }
    if (val < target) {
      l = midpoint + 1;
    } else {
      r = midpoint - 1;
    }
  }
}

int main() {
  vector<int> x = {1, 3};
  cout << searchInsert(x, 0) << endl;
  return 0;
}
