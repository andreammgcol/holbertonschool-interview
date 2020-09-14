#include "palindrome.h"

/**
 * len_n - check argv
 * @n: unsigned long number
 * Return: numbers entry by argv for n
 */
int len_n(unsigned long n)
{
	int args = 0;

	while (n > 0)
	{
		n = n / 10;
		args++;
	}

	return (args);
}

/**
 * is_palindrome - function that checks whether or not
 * a given unsigned integer is a palindrome
 * @n: unsigned long number
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long store[20];
	int num, i;

	num = len_n(n);

	for (i = 0; i < num / 2; i++)
	{
		store[i] = n % 10;
		n = n / 10;
	}
	i--;

	if (num % 2 == 1)
		n = n / 10;

	for (; i >= 0; i--)
	{
		if (n % 10 != store[i])
			return (0);
		n = n / 10;
	}
	return (1);
}
