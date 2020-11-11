/**
 * This program computes the product of the first n
 * prime numbers.  Optionally, it allows the user
 * to provide n as a command line argument, but
 * defaults to the first n = 10 primes
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * This function takes an integer array (of size n) and
 * returns the product of its elements.  It returns 0 if the
 * array is NULL or if its size is <= 0
 */

int product(int *arr, int n) {
  if(n == 0) return 0;
  int i;
  int total = 1;
  for(i=0; i<n; i++) {
    total *= arr[i];
  }
  return total;
}

/**
 * This function returns an array containing the first
 * n prime numbers
 */
int* getPrimes(int n) {
  int *result = malloc((n)*sizeof(int));
  int i = 0;
  int x = 2;
  while(i < n) {
    if(isPrime(x)) {
      result[i] = x;
      i++;
    }
    if(x == 2){
      x++;
    }else{
      x += 2;
    }
  }
  return result;
}

/**
 * This function determines returns true if the give
 * integer is prime and false otherwise.
 */
int isPrime(int x) {
  if(x < 3) return 1;
  if(x % 2 == 0) return 0;
 
  for(int i=3; i<=round(sqrt(x)); i+=2) {
    if(x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char **argv) {

  int n = 10; //default to the first 10 primes
  if(argc == 2) {
    n = atoi(argv[1]);
  }

  int *primes = getPrimes(n);

  int s = product(primes, n);
  printf("The product of the first %d primes is %d\n", n, s);

  return 0;
}




