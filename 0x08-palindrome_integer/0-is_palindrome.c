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
 * is_palindrome - Entry point
 * @n: unsigned long number
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned store[200];
    int num, i = 0;
    
    num = len_n(n);
    
    while(i < num / 2)
    {
       store[i] = n % 10;
       i++;
    }
    i--;
    
    if(num % 2 == 1) 
      n = n / 10;
    
    while (i >= 0)
    {
        if (n % 10 != store[i])
            return (0);
        n = n / 10;
        i--;
    }
    return (1);
}
