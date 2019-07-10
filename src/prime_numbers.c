#include "../libs/prime_numbers.h"

prime_numbers_t PRIME_NUMBERS_T() {
  return (prime_numbers_t){ 2, NULL}; 
}

prime_numbers_t initialize_prime_numbers( int max ) {
  prime_numbers_t prime_numbers = { 0, (int *)calloc( max, sizeof(int) ) };
  
  for( prime_numbers.current_index = 0; prime_numbers.current_index < 2; prime_numbers.current_index++ ) {
    prime_numbers.collection[prime_numbers.current_index] =  prime_numbers.current_index + 2; 
  }
  prime_numbers.collection[max - 1] = '\0';
  return prime_numbers;
}

prime_numbers_t generate_prime_numbers( int max ) {
  if( max <= 0 )
    return PRIME_NUMBERS_T();

  int prime, index;
  bool isPrime;
  
  prime_numbers_t prime_numbers = initialize_prime_numbers( max );  

  for( prime = 5; prime <= max; prime+=2 ) {
    isPrime = true;

    for( index = 1; isPrime && prime / prime_numbers.collection[index] >= prime_numbers.collection[index]; index++ )
      if( prime % prime_numbers.collection[index] == 0 )
        isPrime = false;
    
    if( isPrime ) 
      prime_numbers.collection[prime_numbers.current_index++] = prime;
  }

  return prime_numbers;
}