#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using std::string, std::cout, std::endl;

int length_of_continuous_run(string s) {
	int count = 0;
	std::unordered_map<char, int> found;
	for (char c : s) {
		if (found[c])
			return count;
		found[c] = 1;
		count++;
	}
	return count;
}

int lengthOfLongestSubstring(string s) {
	int len = 0;
	for (int i=0; i<s.length(); i++) {
		int thislen = length_of_continuous_run(s.substr(i));
		if (thislen > len)
			len = thislen;
	}
	return len;
}

int main() {
	cout << lengthOfLongestSubstring("pwwkew") << endl;
	return 0;
}

/**
	 Initial solution.
	 Didn't place very well on the leetode histogram.
	 Main problem is that it iterates over the same substrings multiple times.
	 Improvement could be made with a sliding window, only checking the new and removing the old character.
 **/
