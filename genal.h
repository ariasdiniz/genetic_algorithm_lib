#ifndef _ARIA_GENETIC_ALGORITHM_FUNCTIONS_H
#define _ARIA_GENETIC_ALGORITHM_FUNCTIONS_H

#define __MIN 0
#define __MAX 1
#define __NUMBER_OF_WEIGHTS 4
#define __MUTATION_PROBABILITY 0.01
#define __MUTATION_RANGE 0.0000001
#define __REPRODUCTION_RATE 0.15

typedef struct Individual {
  float weights[__NUMBER_OF_WEIGHTS];
  double fitness;
} Individual;

/*
  Create a pointer to an array of individuals. The number of individuals
  is equal to the n_individuals provided. Don't forget to call
  destroy_individuals on this array after usage to free the
  used memory.
*/
Individual **generate_individuals(unsigned int n_individuals);

/*
  Safely destroys an Individual**
*/
void destroy_individuals(Individual **individuals, unsigned int n_individuals);

/*
  This function get two high ranked individuals, take the mean of ther
  weights and substitute in a low ranked individual, effectively
  "killing" the low ranked individual and creating a new one.
*/
int reproduce(Individual **individual, unsigned int n_weights, unsigned int n_individuals);

/*
  This function interates over every weight of every individual
  and slightly modify the weight if the randomized number is
  smaller or equal than the mutation chance.
*/
int mutate(Individual **individual, unsigned int n_weights, unsigned int n_individuals);

/*
  This function calculates the fitness of every individual.
  To be implemented
*/
int fit(Individual **individual);

#endif // _ARIA_GENETIC_ALGORITHM_FUNCTIONS_H