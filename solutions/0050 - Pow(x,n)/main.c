// 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/

#include <stdio.h>
#include <math.h>

/**
	 Second attempt.
	 Ideal solution I think.
	 Recursive solution, whittles down instead of counting up.
 **/

double myPow(double x, long n)
{
	printf("x and n %f\t%d\n", x, n);
	// zero case
	if (n==0)
		return 1;

	// negative case
	if (n<0)
		return myPow(1/x, -n); 

	if (n%2==1)
		return x * myPow(x, n-1);

	return myPow(x*x, n/2);
}


int main()
{
	printf("%f\n", myPow(2.0, 10));
	return 0;
}
