#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
	 Simple solution.
	 Follows the general algorithm used in the problem definition in the leetcode descrption.
	 The two vectors indexing the same is a neat trick, as is basing indexing around the first number to fit for the 4 and 9 cases.
	 There seems to be a cool solution with indexing, that's the way i'd probably do it going forward.
	 Realised you could get some cool log10 solutions early on, but seemed on first thought to be overly bodgy.

				string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
 **/

int first_val(int num) { return num / pow(10, floor(log10(num))); }

string intToRoman(int num) {
  const vector<int> x = {1000, 500, 100, 50, 10, 5, 1};
  const vector<char> y = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
  string outstr = "";
  while (num > 0) {
    int first = first_val(num);
		cout << outstr << " " << num << endl;
    for (int i = 0; i < x.size(); i++) {
      if (num - x[i] >= 0) {
        if (first == 4) { // 4
					cout << "4" << endl;
          num += x[i];
          num -= x[i - 1];
          outstr.append(1, y[i]);
          outstr.append(1, y[i - 1]);
					break;
        } else if (first == 9) { // 9
					cout << "9" << endl;
          num += x[i+1];
          num -= x[i - 1];
          outstr.append(1, y[i+1]);
          outstr.append(1, y[i - 1]);
					break;
        } else {
					cout << "else" << endl;
          num -= x[i];
          outstr.append(1, y[i]);
					break;
        }
      }
    }
  }
  return outstr;
}

int main() {
	cout << intToRoman(1994) << endl;
	return 0;
}
