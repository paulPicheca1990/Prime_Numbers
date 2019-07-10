#ifndef __PRIME_NUMBERS_H__
#define __PRIME_NUMBERS_H__

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct _prime_numbers_t {
  int current_index;
  int *collection;
} prime_numbers_t;

prime_numbers_t PRIME_NUMBERS_T();

prime_numbers_t initialize_prime_numbers( int size );

prime_numbers_t generate_prime_numbers( int size );

void print_prime_numbers( int *prime_numbers );

#endif