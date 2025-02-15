
#ifndef SELECTION_H_INCLUDE
#define SELECTION_H_INCLUDE
#include "population.h"

/**
 * @brief Performs stochastic universal sampling (SUS) to select individuals from a population.
 * 
 * This function implements the SUS selection method in a genetic algorithm. This method selects individuals
 * with a probability proportional to their fitness, but it does so in a manner that guarantees that the spread
 * of chosen individuals is uniform across the entire population.
 * 
 * @note The function assumes that 'population' is a valid array of 'individual' structures of at least 'population_size' size.
 * It also assumes that the 'fitness' field of each individual is an integer.
 * The population after the function call will be modified to contain the selected individuals.
 * Make sure 'num_select' is less than or equal to 'population_size'.
 * 
 * @param population A pointer to the first individual in the population array from which selection will be made.
 * @param population_size The number of individuals in the population.
 * @param num_select The number of individuals to be selected from the population.
 *
 * @return void
 *
 * @warning This function overwrites the original population array with the selected individuals. 
 */
void stochastic_universal_sampling(individual population[], int population_size, int num_select);

/**
 * @brief Performs truncation selection operation to select top-fittest individuals from a population.
 *
 * This function sorts the population in descending order of fitness and selects the top 'num_select'
 * individuals. It then replaces the original population with the selected individuals.
 *
 * @note The function assumes that 'population' is a valid array of 'individual' structures of at least 
 * 'population_size' size. It also assumes that the 'fitness' field of each individual is an integer.
 * The population after the function call will be modified to contain the selected individuals.
 * Ensure 'num_select' is less than or equal to 'population_size'.
 *
 * @param population A pointer to the first individual in the population array from which selection will be made.
 * @param population_size The number of individuals in the population.
 * @param selection_size The number of top-fittest individuals to be selected from the population.
 *
 * @return void
 *
 * @warning This function overwrites the original population array with the selected individuals. 
 */
void truncate_selection(individual population[], int population_size, int selection_size);

#endif