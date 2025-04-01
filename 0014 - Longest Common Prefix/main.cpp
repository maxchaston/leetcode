#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
	 Better solution.
 **/

string longestCommonPrefix(vector<string> &strs) {
  string outstr = "";
  int minlen = strs[0].length();
  for (string s : strs) {
    if (s.length() < minlen)
      minlen = s.length();
  }
  for (int j = 0; j < minlen; j++) {
    char c = strs[0][j];
    for (int i = 0; i < strs.size(); i++) {
      if (c != strs[i][j]) {
				return outstr;
      }
    }
    outstr.append(1, c);
  }
  return outstr;
}

int main() {
  vector<string> v = {"dog", "racecar", "car"};
  cout << longestCommonPrefix(v) << endl;
  return 0;
}
