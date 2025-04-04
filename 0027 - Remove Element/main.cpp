#include <vector>
using namespace std;

/**
         Neat solution I think.
         First attempt.
         Need a separate valcount variable as otherwise the count could be
 thrown off by a large number of the val for deletion.
 **/

int removeElement(vector<int> &nums, int val) {
  int valcount = 0;
  int k = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == val) {
      valcount++;
    } else {
      nums[i - valcount] = nums[i];
      k++;
    }
  }
  return k;
}
