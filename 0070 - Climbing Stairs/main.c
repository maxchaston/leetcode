// 70. Climbing Stairs

/**
	 Was tired so didn't think too much about the implementation.
	 Figured it was fibonacci or something and it was.
**/

#include <stdio.h>

int climbStairs(int n)
{
	int prev=0;
	int curr=1;
	for (int i=0; i<n; i++)
	{
		int tmp = curr;
		curr = prev+curr;
		prev = tmp;
	}
	return curr;
}

int main()
{
	printf("%d\n", climbStairs(45));
	return 0;
}
