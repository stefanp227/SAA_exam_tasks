/*
	Даден е масив A, с n на брой положителни целочислени елементи.
	Да се намери най-големият общ делител, чрез алгоритъм на Евклид
	на максималния четен и минималния нечетен елемент на масива.

	
	Ако имате въпроси, не се притеснявайте да питате. :)  
*/

#include <stdio.h>
#include <stdlib.h>

int euclid_gcd(int max_even, int min_odd) {
  int temp;

  if((max_even == 0) || (min_odd == 0))
        return 0;
    else if((max_even < 0) || (min_odd < 0))
        return -1;

    do
    {
        temp = max_even % min_odd;
        if(temp == 0)
            break;
        max_even = min_odd;
        min_odd = temp;
    }
    while(1);

    return min_odd;
}

int main() {
  int array[10] = {23, 41, 52, 66, 184, 10, 18, 24, 99, 166};
  int max_even, min_odd;
  max_even = min_odd = array[0];
  int i;

  for(i = 0; i < 10; i++) {
    if(array[i] % 2 == 0) {
      if(max_even < array[i]) {
        max_even = array[i];
      }
    } else {
      if(min_odd > array[i]) {
        min_odd = array[i];
      }
    }
  }

  int gcd = euclid_gcd(max_even, min_odd);

  printf("The GCD of %d and %d is %d", max_even, min_odd, gcd);

  return 0;
}
