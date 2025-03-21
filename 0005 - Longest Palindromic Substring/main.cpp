#include <string>
#include <iostream>
using std::string, std::cout, std::endl;

/**
	 Solved using intuition, psyched myself out by looking at Manacher's
	 algorithm, which would be out of scope for this in an interview.
	 Goes letter by letter, expanding a radius around the centre index while
	 the substring remains a palindrome.

	 O(n^2)

	 By adding a filler character between all letters, you can treat
	 odd and even palindromes the same way.
	 A very neat trick.
 **/

string pad_s(string s) {
	string r = "";
	for (char c : s) {
		r.push_back('|');
		r.push_back(c);
	}
	r.push_back('|');
	return r;
}

// bool isPalindrome(string s) {
// 	cout << s << endl;
// 	if (s.size() <= 1)
// 		return true;
// 	if (s.front() == s.back())
// 		return isPalindrome(s.substr(1,s.size()-2));
// 	return false;
// }

string longestPalindrome(string s) {
	string longest = "";
	s = pad_s(s);
	for (int i=0; i<s.size(); i++) {
		// i is the index of the centre of the tested palindrome
		int radius = 0;
		while (i-radius>=0 && i+radius<s.size() && s[i-radius] == s[i+radius]) {
			radius++;
		}
		radius--;
		if (radius*2+1 > longest.length()) {
			longest = s.substr(i-radius, radius*2+1);
		}
	}
	string ret = "";
	for (int i=0; i<longest.size(); i++) {
		if (i%2)
			ret.push_back(longest[i]);
	}
	return ret;
}

int main() {
	cout << longestPalindrome("babad") << endl;
	// cout << isPalindrome("abba") << endl;
	return 0;
}
