//2 approaches:
/* Function to calculate x raised to the power y in O(logn)*/
int power(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

////////////////////////////////////////////////////

// Iterative C program to implement pow(x, n)
#include <stdio.h>

/* Iterative Function to calculate (x^y) in O(logy) */
int power(int x, unsigned int y)
{
	int res = 1; // Initialize result

	while (y > 0) {
		// If y is odd, multiply x with result
		if (y & 1)
			res = res * x;

		// y must be even now
		y = y >> 1; // y = y/2
		x = x * x; // Change x to x^2
	}
	return res;
}

// Driver program to test above functions
int main()
{
	int x = 3;
	unsigned int y = 5;

	printf("Power is %d", power(x, y));

	return 0;
}

