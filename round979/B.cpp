#include <stdio.h>

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("1");
		while (n-- > 1) printf("0");
		printf("\n");	
	}
	return 0;
}

/*
 * Let's explore the sample outputs.
 *
 * f(0) = 1, g(0) = 0
 * oneness = |1 - 0| = 1
 *
 * f(01) = 1, g(01) = 2
 * oneness = |1 - 2| = 1
 *
 * f(010) = 3, g(010) = 4
 * oneness = |3 - 4| = 1
 *
 * Is it possible to keep the oneness 1?
 *
 * We try the string w of the form 100...0.
 * 
 * f(w) = 2^(n - 1) - 1, g(w) = 2^(n - 1).
 *
 * Therefore, |f(w) - g(w)| = 1.
 *
 * Is it possible to have oneness = 0?
 * 
 * Suppose n > 0.
 *
 * Suppose f(t) = g(t) = 0, then t must not have any 1's. But, that means that it must contain at least one 0. Hence, f(t) = 1. Contradiction.
 *
 * Suppose f(t) = g(t) != 0, then t must have at least one 1. But, f(t) = 2^<number of 0's> - 1 and g(t) = <number of 1's> * 2^<number of 0's>.
 *
 * f(t) = g(t) <=> (1 - <number of 1's>) * 2^<number of 0's> = 1.
 *
 * This is only satisfied when <number of 1's> = <number of 0's> = 0. Contradiction. 
 */
