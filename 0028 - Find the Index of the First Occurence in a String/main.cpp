#include <string>
#include <iostream>
using std::string, std::cout, std::endl;

int strStr(string haystack, string needle) {
	int needle_index=0;
	for (int i=0; i<haystack.length(); i++) {
		cout << haystack[i] << " " << needle[needle_index] << endl;
		for (int j=i; j<haystack.length(); j++) {
			if (haystack[j] == needle[needle_index]) {
				cout << haystack[j] << " " << needle[needle_index] << endl;
				if (needle_index == needle.length()-1)
					return i;
				needle_index++;
			}
			else
				break;
		}
		needle_index=0;
	}
	return -1;
}

int main() {
	cout << strStr("mississippi", "issip") << endl;
	return -1;
}

/**
	 Iterates through the haystack and attempts to forward match the needle string.
	 Breaks out when it stops maching.
	 Seems surprisingly optimised considering it could run the forward match a lot in a worst case (close matches).
	 Seems the rational way to go about it, to prevent nested strings from running amok (mississippi, issip).
	 0ms runtime and beats 100%, so I assume I did something right.
 **/
