#include <cmath>
#include <iostream>
#include <limits.h>
using std::cout, std::endl;

/**
         Pretty easy one. The comparison to INT_MAX and INT_MIN did not come
 immediately. My first instinct was to check log10 for 10 digits, then check
 against the max and min but that's just a superfluous check. The last digit
 check for 7 and -8 are the only real sticking points.
 **/

int reverse(signed long x) {
  int ret = 0;
  while (x != 0) {
    cout << ret << endl;
    cout << x << endl;
    int last_dig = x % 10;
    if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && last_dig > 7)) {
      return 0;
    }
    if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && last_dig < -8)) {
      return 0;
    }
    ret = ret * 10;
    ret += last_dig;
    x = x / 10;
  }
  return ret;
}

int main() {
  cout << reverse(123) << endl;
  return 0;
}
