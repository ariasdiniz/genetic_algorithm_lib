# Genetic Algorithm Library in C

This is a Genetic Algorithm (GA) library implemented in C. It provides the tools to create and evolve a population of solutions to optimization problems using principles inspired by natural selection.

## Features

  - **Customizable Fitness Function**: Define your own fitness function to evaluate how well each individual solves your problem.
  - **Mutation and Reproduction**: Includes mechanisms for mutating and reproducing individuals to evolve the population towards better solutions.
  - **Scalability**: Adjust the number of individuals and iterations for better results at the cost of greater computing time.

## Getting Started
### Prerequisites

  - C compiler (e.g., gcc).
  - Standard C libraries: <stdlib.h>, <stdio.h>, <time.h>, <math.h>.

### Installation

  Clone the repository:

```sh
git clone https://github.com/yourusername/genetic-algorithm-lib.git
cd genetic-algorithm-lib
```

Include the library in your project:

```c
#include "path/to/genal.h"
``` 
## Usage

Here's an example demonstrating the use of the library to solve a simple problem.

```c

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "path/to/genal.h"

/*
  This code aims to demonstrate the functioning of the genetic algorithm.

  Problem: Determine the number of unique products a basket can carry with a weight limit of 8 kg.
  Weights of products: 3 kg, 4 kg, 5 kg, and 8 kg.
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
```

### Functions

  - **generate_individuals**(n_individuals, mutation_rate, mutation_step, reproduction_rate, n_weights, min_weight, max_weight): Initializes a population of individuals.

      - n_individuals: Number of individuals in the population.
      - mutation_rate: Probability of mutation for each weight.
      - mutation_step: Maximum change for each mutation.
      - reproduction_rate: Fraction of the population selected for reproduction.
      - n_weights: Number of weights (genes) per individual.
      - min_weight: Minimum value for weights.
      - max_weight: Maximum value for weights.

  - **fit**(individuals, fitness_function): Evaluates the fitness of each individual using the provided fitness function.
      - individuals: Population of individuals.
      - fitness_function: Function to calculate the fitness of each individual.

  - **mutate**(individuals): Applies mutations to the population.

  - **reproduce**(individuals): Selects individuals based on their fitness and produces offspring.

  - **destroy_individuals**(individuals): Frees memory allocated for the population.

### Example Explained

  **Problem Definition**: We have a basket that can carry 8 kg and a set of 4 products with weights 3 kg, 4 kg, 5 kg, and 8 kg. The goal is to determine the optimal combination of products to maximize the basket's weight without exceeding 8 kg.

  **Fitness Function (fun)**: Calculates the fitness of each individual by summing the weights of selected products. The fitness is zero if the total weight exceeds 8 kg.

  **Main Function**: Initializes the population, runs the genetic algorithm for a specified number of iterations, and prints the weights of the best individual.

## Notes

  - For better results, increase the number of individuals and iterations at the cost of greater computing time.
  - Customize the fitness function to suit different optimization problems.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

  Inspired by natural selection and evolutionary biology principles.