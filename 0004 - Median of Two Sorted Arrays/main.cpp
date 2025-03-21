#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>

using std::vector, std::cout, std::endl;

/**
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
**/

/**
	 This one was quite tricky, my intuition was not to do this at all.
	 The merge list method was obvious but did not meet the time requirements.
	 This binary search method was not immediately obvious, had to look the logic up online.
	 The finagling of oob indexes was a little troublesome to think about in relation to the wider method.
 **/


double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
	if (nums1.size() < nums2.size()) // ensure nums1 is the larger array
		return findMedianSortedArrays(nums2, nums1);

	int total_size = nums1.size() + nums2.size();
	int half = (total_size + 1) / 2;

	// pointers for window on smaller array
	int l = 0;
	int r = nums2.size();


	while (l <= r) {
		cout << "l: " << l << ", r: " << r << endl;
		int indexA = (l+r)/2; // midpoint of the nums2 pointers
		int indexB = half - indexA; // index of nums1 pointer

		cout << indexB << " " << indexA << endl;

		int leftA = (indexA == 0) ? INT_MIN : nums2[indexA-1] ;
		int rightA = (indexA == nums2.size()) ? INT_MAX : nums2[indexA];
		int leftB = (indexB == 0) ? INT_MIN : nums1[indexB-1];
		int rightB = (indexB == nums1.size()) ? INT_MAX : nums1[indexB];

		cout << leftB << " " << rightB << " " << leftA << " " << rightA << endl; 

		if (leftA <= rightB && leftB <= rightA) { // correct partition
			cout << "CORRECT" << endl;
			if (total_size%2==1)
				return std::max(leftB, leftA);
			else
				return (std::max(leftB, leftA) + std::min(rightB, rightA)) / 2.0;
		} else if (leftA > rightB) {
			r = indexA - 1;
		} else {
			l = indexA + 1;
		}
	}
    return 0.0;
};

int main() {
	cout << findMedianSortedArrays(vector<int>{1,3}, vector<int>{2}) << endl;
	return 0;
}
