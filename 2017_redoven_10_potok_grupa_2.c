/*

      Намиране на най - голям общ делител на масив от числа, 
      след което да се сортират.	


      Ако имате въпроси, не се притеснявайте да питате. :)
*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
int findGCD(int arr[], int n) {
    int result = arr[0];
    int i;

    for (i=0 ; i <= n; i++)
        result = gcd(arr[i], result);
 
    return result;
}
 
int main() {
    int arr[] = {2, 312, 126, 3168, 514, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i, j, temp;

    printf("%d", findGCD(arr, n));

    for (i = 0; i < n; i++) {
	for(j = 0; j < (n - i + 1); j++) {
	    if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
	}
    }

    for(i = 0; i < n; i++) {
       printf("%d", arr[i]);
    }

    return 0;
}
