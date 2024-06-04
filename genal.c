#include <stdlib.h>
#include <math.h>
#include "genal.h"

static float random_number() {
  float scale = rand() / (float)RAND_MAX;
  return __MIN + scale * (__MAX - __MIN);
}

/*
  Create a pointer to an array of individuals. The number of individuals
  is equal to the n_individuals provided. Don't forget to call
  destroy_individuals on this array after usage to free the
  used memory.
*/
Individual **generate_individuals(unsigned int n_individuals) {
  Individual **individuals = malloc(sizeof(Individual *) * n_individuals);
  for (int i = 0; i < n_individuals; i ++) {
    individuals[i] = malloc(sizeof(Individual));
    if (individuals[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(individuals[j]);
      }
      free(individuals);
      return NULL;
    }
  }
  for (int i = 0; i < n_individuals; i++) {
    for (int j = 0; j < __NUMBER_OF_WEIGHTS; j++) {
      individuals[i]->weights[j] = random_number();
    }
    individuals[i]->fitness = 0.0;
  }
  return individuals;
}

/*
  Safely destroys an Individual**
*/
void destroy_individuals(Individual **individuals, unsigned int n_individuals) {
  for (int i = 0; i < n_individuals; i++) {
    free(individuals[i]);
  }
  free(individuals);
}

/*
  These functions were declared to be used only inside this .c file.
  Do not alter them to be used externally.
*/

static float mutation_prob() {
  return rand() / (float)RAND_MAX;
}

static float mutation() {
  float scale = mutation_prob() * __MUTATION_RANGE;
  return (-__MUTATION_RANGE / 2.0) + scale;
}

int compare_individuals(const void* a, const void* b) {
    Individual *arg1 = (Individual *)a;
    Individual *arg2 = (Individual *)b;

    if (arg1->fitness < arg2->fitness) return -1;
    if (arg1->fitness > arg2->fitness) return 1;
    return 0;
}

void reproduction(Individual *ind1, Individual *ind2, Individual *result, unsigned int n_weights) {
  for (int i = 0; i < n_weights; i++) {
    result->weights[i] = (ind1->weights[i] + ind2->weights[i]) / 2.0;
  }
}

/*
  These functions are meant to be use outside this .c file and their
  interfaces are declared in functions.h
*/

/*
  This function get two high ranked individuals, take the mean of ther
  weights and substitute in a low ranked individual, effectively
  "killing" the low ranked individual and creating a new one.
*/
int reproduce(Individual **individual, unsigned int n_weights, unsigned int n_individuals) {
  if (individual == NULL) {
    return -1;
  }
  unsigned int array_size = (sizeof(individual) / sizeof(individual[0]));
  unsigned int individuals_to_reproduce = floor(array_size * __REPRODUCTION_RATE);
  qsort(individual, array_size, sizeof(Individual), compare_individuals);
  for (int i = 0; i < floor(individuals_to_reproduce / 2); i ++)  {
    reproduction(individual[i*2], individual[(i*2)+1], individual[n_individuals-1-i], n_weights);
  }  
  return 0;
}

/*
  This function interates over every weight of every individual
  and slightly modify the weight if the randomized number is
  smaller or equal than the mutation chance.
*/
int mutate(Individual **individual, unsigned int n_weights, unsigned int n_individuals) {
  if (individual == NULL || n_weights < 1) {
    return -1;
  }
  for (unsigned int i = 0; i < n_individuals; i++) {
    for (unsigned int j = 0; j < n_weights; j++) {
      if (mutation_prob() <= __MUTATION_PROBABILITY) {
        individual[i]->weights[j] += mutation();
      }
    }
  }
  return 0;
}


/*
  This function calculates the fitness of every individual.
  To be implemented
*/
int fit(Individual **individual) {
  // Implement me
  return 0;
}