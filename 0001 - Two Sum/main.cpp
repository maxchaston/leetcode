#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
	 O(n) solution.
	 Returning to it after reading a bit about it in other problems.
	 One-pass hash map solution.
 **/

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> h = {}; // num and index
	for (int i=0; i<nums.size(); i++) {
		if (h.find(target-nums[i]) != h.end()) {
			return {i, h[target-nums[i]]};
		}
		h[nums[i]] = i;
	}
	return {0, 0};
}
