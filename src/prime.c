/*
	My take on determining primes till nth position in a whole number set.
	We deduce that primes are only odd, besides 2 the special case, thus we should increment our search in 2s whilst starting at 3.
	We use mod to determine whether a number is divisble by any previous prime in our stored set
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	/* array of primes, set the first to 2 - our starting prime */
	int primes[2005001];
	primes[0] = 2;
	int length = 1;
	clock_t begin = clock();
	/* loop from 3, the next number needed to be tested 
	 * we loop i till n, where n is our upper range limit
	 * since we are only interested in odd numbers, we increments by 2 to skip even numbers
	 */
	for(int i = 3; i < 20000001; i = i + 2){
		/*
			We set up three vars needed, trigger which helps determine whether the current number i is divisible.
			x, our starting point in our prime array
			upperRange, the point where we should stop searching on the number line

			we set upperRange to the sqrt of i as this is the most optimised way to find the absolute limit (i * i). 
			For instance, finding x = 9. we can determine the upper range where we should stop to be sqrt(9) => 3, since 3 * 3 = 9
		*/
		int trigger = 1, x = 0, upperRange = (int)sqrt(i);
		while(primes[x] <= upperRange && trigger != 0){
			trigger = i % primes[x++];
		}
		if(trigger != 0){
			primes[length++] = i;
		}
	}

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Total primes: %d\n", length);
	printf("Last prime: %d\n", primes[length - 1]);
	printf("First 100 primes: \n[%d", primes[0]);
	for (int y = 1; y <= 100; ++y){
		printf(", %d ", primes[y]);
	}
	printf("]\nTime: %f \n", time_spent);
	return 0;
}