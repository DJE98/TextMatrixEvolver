#ifndef POPULATION_H_INCLUDE
#define POPULATION_H_INCLUDE
typedef struct individual{
    char* genome;
    int fitness;
} individual;

/**
 * @brief Creates an individual with a fitness score of 0 and a random alphabetic genome.
 * 
 * This function creates a genome of size `x` * `y` for a given individual, with each character in the genome being a random uppercase alphabetical letter. 
 * It initializes the individual's fitness to 0. The genome string is null-terminated.
 * 
 * @note The function expects 'one_individual' to be a valid pointer to an 'individual' structure.
 * The function will allocate memory for the 'genome' field of the 'individual' structure.
 * It also assumes that `random()` generates a random integer, and the seed for this function should be set.
 * 
 * @param one_individual A pointer to the individual for whom a random genome is to be generated.
 * @param x The width in characters of the genome.
 * @param y The height in characters of the genome.
 *
 * @return void
 */
void generate_random_individual(individual* one_individual, int x, int y);

/**
 * @brief Generates a population of individuals with random alphabetic genomes and fitness scores of 0.
 * 
 * This function generates a specified number of individuals, each with a random genome of size `x` * `y`.
 * The generation of random genomes is done by calling the `generate_random_individual` function.
 * 
 * @note The function assumes that 'population' is a valid array of 'individual' structures of at least 'number' size. 
 * This function will allocate memory for the 'genome' field of each 'individual' structure.
 * It also assumes that `random()` generates a random integer, and the seed for this function should be set.
 * 
 * @param population A pointer to the first individual in the population array to be filled with random genomes.
 * @param x The width in characters of the genome for each individual in the population.
 * @param y The height in characters of the genome for each individual in the population.
 * @param number The number of individuals in the population to be generated.
 *
 * @return void
 */
void generate_random_population(individual population[], int x, int y, int number);

/**
 * @brief Frees the memory allocated for the genomes of a population of individuals.
 * 
 * This function iterates through a population of individuals, freeing the memory that was allocated for each individual's genome.
 * It's assumed that the 'genome' field of each individual was dynamically allocated.
 * 
 * @note The function assumes that 'population' is a valid array of 'individual' structures of at least 'number' size.
 * It also assumes that the 'genome' field of each individual was previously allocated dynamically.
 * After this function is called, the 'genome' field of each individual will be a dangling pointer.
 * 
 * @param population A pointer to the first individual in the population array whose genomes are to be freed.
 * @param number The number of individuals in the population.
 *
 * @return void
 */
void free_population(individual population[], int number);

/**
 * @brief Prints the genomes and fitness scores of a population of individuals.
 * 
 * This function iterates through a population of individuals, printing each individual's genome and fitness value to the standard output.
 * The genome and fitness are separated by a tab character, and each individual is printed on a new line.
 * 
 * @note The function assumes that 'population' is a valid array of 'individual' structures of at least 'population_size' size.
 * It also assumes that the 'genome' field of each individual is a null-terminated C-string.
 * 
 * @param population A pointer to the first individual in the population array to be printed.
 * @param population_size The number of individuals in the population.
 *
 * @return void
 */
void print_population(individual population [], int population_size);

/**
 * @brief Prints the genome and fitness score of the individual with the highest fitness score in a population.
 * 
 * This function iterates through a population of individuals, finding the individual with the highest fitness score.
 * It then prints the genome and fitness score of this individual to the standard output.
 * 
 * @note The function assumes that 'population' is a valid array of 'individual' structures of at least 'population_size' size.
 * It also assumes that the 'genome' field of each individual is a null-terminated C-string.
 * 
 * @param population A pointer to the first individual in the population array to be searched.
 * @param population_size The number of individuals in the population.
 *
 * @return void
 */
void print_best_individual(individual population [], int population_size);

/**
 * @brief Compares two individuals based on their fitness.
 *
 * It subtracts the fitness of the first individual from that of the second, so that
 * qsort() can sort the individuals in descending order of fitness.
 *
 * @param a Pointer to the first individual.
 * @param b Pointer to the second individual.
 * 
 * @return An integer less than, equal to, or greater than zero if the fitness of the 
 * first individual is greater than, equal to, or less than the fitness of the second individual, respectively.
 */
int compare_individuals_by_fitness(const void *a, const void *b);

#endif