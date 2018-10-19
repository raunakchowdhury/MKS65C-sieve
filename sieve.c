# include "sieve.h"
# include <stdio.h>
# include <stdlib.h>

int sieve(int num_prime){
  int num; //length
  int prime; //returned prime
  double estimate = log(num_prime); //find log
  //printf("Log: %f\n", estimate);
  if (num_prime < 5000){
    num = (int)(1.3 * num_prime * estimate + 10);
  }
  else{
    num = (int)(1.15 * num_prime * estimate);
  }
  //printf("Num: %d\n", num);
  char * num_array = calloc(sizeof(char), num); // initialize array

  // =========== ACTUAL ALGORITHM =========
  int index;
  int second_index;
  int num_prime_ctr = 0; // the current prime count
  int sqrt_num = (int) sqrt(num); // the limit at which all possible composites have been filled
  for (index = 2; index < num; index++){
    // deal with nums not marked off
    if (num_array[index] != 'a'){
      //save the last prime
      prime = index;
      num_prime_ctr++;
      // return the prime if the num matches the num_prime
      if (num_prime_ctr == num_prime){
        return prime;
      }
      // don't iterate if you're at index sqrt(num)
      if (index < sqrt_num){
      // loop through the array, marking off any composite nums
        second_index = index;
        while(second_index < num){
          if (num_array[second_index] != 'a'){
              num_array[second_index] = 'a';
          }
          second_index += index;
        }
      }
    }
  }
  // once you've hit the end, just return
  // the print statement being printed out indicates that the array size has been exhausted
  printf("Prime %d returned!\n", num_prime_ctr);
  return prime;
}
