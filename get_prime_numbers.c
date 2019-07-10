#include <stdio.h>
#include "./libs/prime_numbers.h"

#define MAX_COLUMNS 8

void print_prime_numbers( int *prime_numbers ) {  
  int count = 0;
  while( *prime_numbers != 0 ) {
    printf( "%8d ", *prime_numbers++ );

    if( count++ > MAX_COLUMNS ) {
      printf("\n");
      count = 0;
    }
      
  }
}

int main( int argc, char *argv[] ){   
  int max = 20;

  if( argc > 1 ) 
    max = atoi(argv[1]) != 0 ? atoi(argv[1]) : 20;
  
  prime_numbers_t prime_numbers = generate_prime_numbers(max);
  print_prime_numbers( prime_numbers.collection );
  free( prime_numbers.collection );
  return 0;
}