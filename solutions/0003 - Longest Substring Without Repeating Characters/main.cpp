#include <string>
#include <iostream>
#include <unordered_map>

using std::string, std::cout, std::endl;

/**
	 Iterating through one character at a time.
	 If new character is not part of the substring, add to map.
	 If it is, keep shifting left side of sliding window and removing from map until a valid substring is found.
	 Can store the index of the letter in the map.
 **/

int lengthOfLongestSubstring(string s) {
	int max_len = 0;
	std::unordered_map<char, int> map;
	int left = 0;
	for (int right=0; right<s.length(); right++) {

		if (map.count(s[right]) != 0) { // new value is already in the map
			for (;left<=map[s[right]];left++) { // catch left side of window up to duplicate
				map.erase(s[left]);
			}
			map[s[right]] = right;
		}

		else { // new value not in the map
			max_len = (right+1-left)>max_len ? (right+1-left) : max_len;
			map[s[right]] = right;
		}
	}
	return max_len;
}

int main() {
	cout << lengthOfLongestSubstring("abcabcbb") << endl;
	return 0;
}

/**
	 Second solution.
	 Sliding window approach.
	 Still didn't place very well on the leetode histogram.
	 I assume this time it's because of the map.count() function being poorly optimised.
 **/
