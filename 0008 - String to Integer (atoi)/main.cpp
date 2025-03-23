#include <iostream>
#include <limits.h>
#include <string>
using namespace std;

/**
         Pretty easy one.
         Worked first try.
         Useful to have done question 7 just before this, as it uses the same
 INT_MAX and INT_MIN checker.
 **/

int myAtoi(string s) {
  int ret = 0;
  bool neg = false;
  int algo_step = 1;
  for (char c : s) {
    switch (algo_step) {
    case 1: // whitespace
      if (c == ' ')
        break;
      algo_step = 2;
    case 2: // signedness
      algo_step = 3;
      if (c == '-') {
        neg = true;
        break;
      }
      if (c == '+')
        break;
    case 3:
      if (c <= '9' && c >= '0') { // digit
        if (!neg && (ret > INT_MAX / 10 || ret == INT_MAX / 10 && c - '0' > 7))
          return INT_MAX;
        if (neg && (-ret < INT_MIN / 10 ||
                    -ret == INT_MIN / 10 &&
                        c - '0' >= 8)) // fixes problem with overflow in case of
                                       // 8, in which case it's already INT_MIN
          return INT_MIN;
        ret = ret * 10;
        ret += c - '0';
      } else {
        return ret * (neg ? -1 : 1);
      }
    }
  }
  return ret * (neg ? -1 : 1);
}

int main() {
  cout << myAtoi("1337c0d3") << endl;
  return 0;
}
