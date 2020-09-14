#include "palindrome.h"


/**
 * is_palindrome - Entry point
 * @n: unsigned long number
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned store[200];
    int num = 0; i = 0;
    
    while (n > 0)
	{
		n = n / 10;
		num++;
	}
    
    while(i < num / 2)
    {
       store[i] = n % 10;
       i++;
    }
    i--;
    
    if(num % 2 == 1) 
      n = n / 10;
    
    for (; i >= 0, i--)
    {
        if (n % 10 != store[i])
            return (0);
        n = n / 10;
    }
    return (1);
}
