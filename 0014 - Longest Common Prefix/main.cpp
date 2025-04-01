#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
         Initial solution, iterates through all one by one.
         Pretty slow, just a general solution.
         Better way would be to iterate one at a time through all, because you
 have the change to exit sooner.
 **/

string longestCommonPrefix(vector<string> &strs) {
  string outstr = strs[0];
  for (int i = 1; i < strs.size(); i++) {
    cout << strs[i] << endl;
    cout << outstr << endl;
    string tmp = "";
    for (int j = 0; j < strs[i].length(); j++) {
      if (outstr[j] != strs[i][j]) {
        cout << "ding" << endl;
        if (j == 0)
          return "";
        outstr = outstr.substr(0, j);
        goto end;
      }
    }
    outstr = strs[i];
  end:
  }
  return outstr;
}

int main() {
  vector<string> v = {"dog", "racecar", "car"};
  cout << longestCommonPrefix(v) << endl;
  return 0;
}
