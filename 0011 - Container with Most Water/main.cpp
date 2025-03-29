#include <algorithm>
#include <iostream>
#include <vector>
using std::vector, std::cout, std::endl, std::min, std::max;

/**
         Initial obvious O(n^2) solution ran out of time.
         Better O(n) solution involves starting at the widest point, then
 sliding the left and right pointers inwards depending on which is smaller.
         The water level depends on the lower of the two walls, so moving the
 lower inwards in chance of finding a taller one is the ideal move.
 **/

int maxArea(vector<int> &height) {
  int max_vol = 0;
  int i = 0;
  int j = height.size() - 1;
  while (i < j) {
    max_vol = max(max_vol, (j - i) * min(height[i], height[j]));
    if (height[i] < height[j]) {
      i++;
    } else {
      j--;
    }
  }
  return max_vol;
}
