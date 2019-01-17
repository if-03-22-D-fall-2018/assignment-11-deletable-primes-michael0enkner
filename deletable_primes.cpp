/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
 #include "deletable_primes.h"
 #include <math.h>


 unsigned long remove_digit(int i, unsigned long num)
 {
   unsigned long left_site = 0 ;
   unsigned long  right_site = 0;
   unsigned long total = 0;

   if (i == 0)
   {
     return num / 10;
   }
   left_site = num / pow(10 , i + 1);
   right_site = num % (unsigned long)pow(10 , i);
   total = left_site * pow(10 , i) + right_site;

   return total;
 }

 int get_ways(unsigned long num)
 {
   int len = 0;
   for (int i = 0; i < get_length(num); i++)
   {
     if (get_length(num) == 1)
     {
       if (is_prime(num) == true)
       {
         return 1;
       }
       return 0;
     }
     else if (is_prime(remove_digit(i,num)) )
     {
       len += get_ways(remove_digit(i,num));
     }

    }
   return len;
 }

 int get_length(unsigned long num)
{
  unsigned long  clone = num;
  unsigned long  len = 0;
  if (num < 10)
  {
    return 1;
  }
  while (clone != 0)
  {
    clone = clone/10;
    len++;
  }
  return len;
}

bool is_prime(unsigned long num)
{
  if (num == 1)
  {
    return false;
  }
  unsigned long  i = 2;
  unsigned long  cloned_num = num;
  while (i <= sqrt(num))
  {
    if (cloned_num % i == 0)
    {
      return false;
    }
    i++;
  }
  return true;
}
