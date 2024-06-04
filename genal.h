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

Individual **generate_individuals(unsigned int n_individuals);
void destroy_individuals(Individual **individuals, unsigned int n_individuals);

int reproduce(Individual **individual, unsigned int n_weights, unsigned int n_individuals);
int mutate(Individual **individual, unsigned int n_weights, unsigned int n_individuals);
int fit(Individual **individual);

#endif // _ARIA_GENETIC_ALGORITHM_FUNCTIONS_H