#include <iostream>
#include <vector>
using namespace std;

/**
	 Better binary search solution.
	 Slight more clean, better exit condition.
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
    int midpoint = (r + l) / 2;
    int val = nums[midpoint];
    if (val == target)
      return midpoint;
    if (r <= l) {
			val = nums[l];
      return l + (val < target ? 1 : 0);
    }
    if (val < target) {
      l = midpoint + 1;
    } else {
      r = midpoint - 1;
    }
  }
}

int main() {
  vector<int> x = {3,5 ,7, 9, 10};
  cout << searchInsert(x, 8) << endl;
  return 0;
}
