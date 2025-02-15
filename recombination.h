
#include "population.h"

/** 
 * @brief Function to perform two point crossover
 * 
 * This function generates two random crossover points within the genomes of the provided parents.
 * It then creates two offspring by swapping the genome segments between these two points from the two parents.
 * The resulting offspring are returned in an array of individual pointers.
 * 
 * @param population population array
 * @param parent_size area of the parents to choose from
 * @param offspring_size area of offsprings to save
 */
void two_point_crossover(individual population[], int parent_size, int offspring_size, int x, int y);