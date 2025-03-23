#include <string>
#include <iostream>
using std::string, std::cout, std::endl;

/**
	 A very easy medium.
	 Just need to catch that it's the largest number.
 **/

int minPartitions(string n) {
        int m = 0;
        for (char c : n) {
            m =  m > c-'0' ? m : c-'0';
        }
        return m;
}

int main() {
	cout << minPartitions("32") << endl;
	return 0;
}
