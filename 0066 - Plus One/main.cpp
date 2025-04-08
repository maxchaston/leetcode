#include <vector>
using namespace std;

/**
	 Initial solution, runs fast and is nothing special.
 **/

vector<int> plusOne(vector<int>& digits) {
	for (int i = digits.size()-1; i>=0; i--) {
		if (digits[i] == 9) {
			digits[i] = 0;
		} else {
			digits[i] += 1;
			return digits;
		}
	}
	digits.insert(digits.begin(), 1);
	return digits;
}
