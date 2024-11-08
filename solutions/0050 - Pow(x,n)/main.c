// 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/

#include <stdio.h>
#include <math.h>

/**
	 Initial attempt.
	 Pretty basic.
	 Multiplies by itself, getting to nearest power of 2 below remaining power needed.
	 Then set the power back to zero and repeats.
 **/

double myPow(double x, long n)
{
	// zero case
	if (n==0)
		return 1;

	// negative case
	int is_neg = 0;
	if (n<0)
	{
		is_neg = 1;
		n = -n;
	}

	// base case
	double sum = 1;
	long remaining_index = n;
	while (remaining_index!=0)
	{
		double tmp_sum = x;
		printf("remaining index %d\n", remaining_index);
		long running_index;
		for (running_index = 2; running_index<remaining_index; running_index*=2)
		{
			printf("%d\t%d\n", running_index, n);
			tmp_sum = tmp_sum*tmp_sum;
		}
		printf("sum %f\n", tmp_sum);
		sum*=tmp_sum;
		remaining_index-=running_index/2;
	}
	if (is_neg)
		return 1/sum;
	return sum;
}


int main()
{
	printf("%f\n", myPow(2.0, -10));
	return 0;
}
