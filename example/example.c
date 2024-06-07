#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "../genal.h"

/*
  This code aims to demonstrate the functioning of the genetic algorithm.

  For this, we have the following problem:

  We have a basket that can carry 8 kg, and we have a set of 4 products.
  Their weights are 3 kg, 4 kg, 5kg and 8 kg, represented by the algorithm's
  weights 0, 1, 2 and 3 respectively.

  The problem is to determine the number of unique products
  this basket can carry. The response is 2 items, one that wights 3 kg
  and another that weights 5 kg.

  For this problem, the best fitted individuals of the algorithm
  have to have, after training, weights like:

  0 => between 0.2 and 1
  1 => approximately 0
  2 => between 0.2 and 1
  3 => approximately 0

  OR

  0 => approximately 0
  1 => approximately 0
  2 => approximately 0
  3 => between 0.2 and 1

  For better results, increase the number of individuals and the
  number of iterations, at the cost of greater computing time.
*/

void *fun(Individuals *individuals) {
  double result = 0;
  int array_size = individuals->n_individuals;
  Individual **individual = individuals->individual_array;
  for (int i = 0; i < array_size; i++) {
    if (individual[i]->weights[0] >= 0.01) result += 3;
    if (individual[i]->weights[1] >= 0.01) result += 4;
    if (individual[i]->weights[2] >= 0.01) result += 5;
    if (individual[i]->weights[3] >= 0.01) result += 8;
    if (result > 8 || result <= 0 ) {
      individual[i]->fitness = 0.0;
      result = 0;
      continue;
    }
    individual[i]->fitness = result;
    result = 0;
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  Individuals *individuals = generate_individuals(100000, 0.05, 0.0001, 0.25, 4, 0.0, 1.0);
  for (int i = 0; i < 1000; i++) {
    fit(individuals, fun);
    mutate(individuals);
    reproduce(individuals);
  }
  printf("Individual 1, weight 0 : %f\n", individuals->individual_array[0]->weights[0]);
  printf("Individual 1, weight 1 : %f\n", individuals->individual_array[0]->weights[1]);
  printf("Individual 1, weight 2 : %f\n", individuals->individual_array[0]->weights[2]);
  printf("Individual 1, weight 3 : %f\n", individuals->individual_array[0]->weights[3]);
  destroy_individuals(individuals);
  return 0;
}
