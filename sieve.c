# include "sieve.h"
# include <stdio.h>
# include <stdlib.h>

int sieve(int targetPrime){
  int num; //length
  int prime = 2; //returned prime
  double estimate = log(targetPrime); //find log
  //printf("Log: %f\n", estimate);
  if (targetPrime < 5000){
    num = (int)(1.3 * targetPrime * estimate + 10);
  }
  else{
    num = (int)(1.15 * targetPrime * estimate);
  }
  num = num / 2; //ignoring evens
  //printf("Num: %d\n", num);
  char * num_array = calloc(sizeof(char), num); // initialize array

  // =========== ACTUAL ALGORITHM =========
  int index;
  int second_index;
  int targetPrime_ctr = 1; // the current prime count; skip by 1
  //int sqrt_num = (int) sqrt(num); // the limit at which all possible composites have been filled
  int interval; // will keep track of how much to increment by now that odd-number mapping is implemented
  for (index = 1; index < num; index++){
    // deal with nums not marked off
    if (num_array[index] != 'a'){
      //save the last prime
      // return the prime if the num matches the targetPrime
      if (targetPrime_ctr == targetPrime){
        return prime;
      }
      prime = 2 * index + 1;
      targetPrime_ctr++;
      // don't iterate if you're at index sqrt(num)
      if (index * index < num){
      // loop through the array, marking off any composite nums
        interval = 2 * index + 1;
        second_index = index;
        for (second_index = index; second_index < num; second_index += interval){
          if (num_array[second_index] != 'a'){
              num_array[second_index] = 'a';
          }
        }
      }
    }
  }
  // once you've hit the end, just return
  // the print statement being printed out indicates that the array size has been exhausted
  printf("Prime %d returned!\n", targetPrime_ctr);
  return prime;
}
