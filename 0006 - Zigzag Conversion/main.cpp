#include <iostream>
#include <string>
using std::string, std::cout, std::endl;

#define print(x)                                                               \
  do {                                                                         \
    cout << x << endl;                                                         \
  } while (false)

/**
         This was a fun one.
         Solved it by drawing it out on paper.
         Essentially just calculating a row at a time by calculating the indexes
 of following letters. Pretty happy with this.
 **/

string convert(string s, int num_rows) {
  string ret_string = "";
  const int cycle = 2 * num_rows - 2;
  cout << "cycle: " << cycle << endl;
  if (s.length() <= num_rows || num_rows == 1)
    return s;
  for (int i = 0; i < num_rows; i++) { // index of current row (zero indexed)
    cout << "index: " << i << endl;
    int offset = 0;
    int remaining = s.length() - i;
    ret_string += s[i]; // add index to string
    print(ret_string);
    if (i == 0 || i == num_rows - 1) { // special case for first and last index
      while ((remaining -= cycle) > 0) {
        print(remaining);
        offset += cycle;
        ret_string += s[i + offset];
        print(ret_string);
      }
    } else { // normal case
      bool jmp_1 = true;
      int initial_jump = (num_rows - i - 1) * 2;
      int initial_dar = (num_rows - i - 1) * 2;
      int following_jump = cycle - initial_jump;
      while ((remaining -= (jmp_1 ? initial_jump : following_jump)) > 0) {
        print(remaining);
        offset += (jmp_1 ? initial_jump : following_jump);
        ret_string += s[i + offset];
        jmp_1 = !jmp_1;
        print(ret_string);
      }
    }
  }
  return ret_string;
}

int main() {
  cout << convert("PAYPALISHIRING", 3) << endl;
  return 0;
}
