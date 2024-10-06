#include <math.h>
#include <stdio.h>
#include <stdbool.h>
bool isPalindrome(int x) {
	if (log10(x) == 0)
		return true;
	char palindrome[1 + (int)log10(x) * sizeof(char)];
	int length = strlen(palindrome);
    sprintf(palindrome, "%d", x);
    /* printf("%s\n", palindrome); */
	for (int i=0; i<floor(length/2); i++) {
		if (palindrome[i] != palindrome[length-1-i]) {
			return false;
		}	
	}
	return true;
}

int main() {
	printf("%s",isPalindrome(10));
	return 0;
}
