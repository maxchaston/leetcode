#include <vector>
using namespace std;

/**
	 Basic solution, uses an intermediary array.
 **/

int removeDuplicates(vector<int> &nums) {
  vector<int> uniq = {};
  int k = 0;
  int curr = -101; // -100 <= nums[i] <= 100
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != curr) {
      curr = nums[i];
      uniq.push_back(curr);
      k++;
    }
  }
  for (int i = 0; i < k; i++) {
    nums[i] = uniq[i];
  }
  return k;
}
