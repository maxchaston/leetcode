// 278. First Bad Version
#include <stdio.h>

int firstbad = 4;

int isBadVersion(int num)
{
	return num>=firstbad;
}

int firstBadVersion(int n)
{
	int lower = 1;
	int upper = n;
	int foundBad = 0;
	if (upper == lower)
		return n;
	while (1)
	{
		int diff = upper-lower;
		int guess = diff/2 + lower;
		if (diff==1)
			return guess+(isBadVersion(guess) ? 0 : 1);
		printf("upper: %d\tlower: %d\tguess:%d\n", upper, lower, guess);
		printf("%d is %s\n", guess, isBadVersion(guess) ? "bad" : "good");
		isBadVersion(guess) ? (upper = guess) : (lower = guess);
	}
}

int main()
{
	printf("First bad is %d\n",firstBadVersion(100));
	return 0;
}
