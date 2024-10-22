//69. Sqrt(x)
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define SQR(x) (x*x)

/**
Implemented Newton-Raphson for (y = x^2 - num)
x^2 = num
**/

int mySqrt(int initial_guess)
{
	double x = initial_guess;
	double epsilon = 0.05;
	while (fabs(SQR(x) - initial_guess) > epsilon)
	{
		double y = SQR(x) - initial_guess;
		double gradient = 2 * x;
		double c = -SQR(x) - initial_guess;
		x = -c / gradient;
	}
	return floor(x);
}

int main()
{
	mySqrt(9485734);
	return 0;
}
