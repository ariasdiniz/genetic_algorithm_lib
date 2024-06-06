#ifndef _ARIA_GENETIC_ALGORITHM_FUNCTIONS_H
#define _ARIA_GENETIC_ALGORITHM_FUNCTIONS_H

typedef struct Individual {
  float *weights;
  double fitness;
} Individual;

typedef struct Individuals {
  Individual **individual_array;
  int n_individuals;
  double mutation_prob, reproduction_rate, mutation_range;
  double number_weights, min, max;
} Individuals;

typedef void *fitfunc(Individuals *individuals);

/*
  Create a pointer to an array of individuals. The number of individuals
  is equal to the n_individuals provided. Don't forget to call
  destroy_individuals on this array after usage to free the
  used memory.
*/
Individuals *generate_individuals(
  unsigned int n_individuals,
  double mutation_prob,
  double mutation_range,
  double reproduction_rate,
  double number_weights,
  double min,
  double max
);

/*
  Safely destroys an Individual**
*/
void destroy_individuals(Individuals *individuals);

/*
  This function get two high ranked individuals, take the mean of ther
  weights and substitute in a low ranked individual, effectively
  "killing" the low ranked individual and creating a new one.
*/
int reproduce(Individuals *individuals);

/*
  This function interates over every weight of every individual
  and slightly modify the weight if the randomized number is
  smaller or equal than the mutation chance.
*/
int mutate(Individuals *individuals);

/*
  This function calculates the fitness of every individual.
  To be implemented
*/
int fit(Individuals *individuals, fitfunc func);

#endif // _ARIA_GENETIC_ALGORITHM_FUNCTIONS_H