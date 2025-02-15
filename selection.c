#include "selection.h"
#include <stdlib.h>

void stochastic_universal_sampling(individual population[], int population_size, int selection_size) {
    
    // Calculate total fitness of the population
    int total_fitness = 0;
    for (int i = 0; i < population_size; i++) {
        total_fitness += population[i].fitness;
    }

    // Compute the distance between the pointers
    int distance = total_fitness / selection_size;

    // Randomly select the start point in the range [0, distance)
    int start = (rand() % distance);

    individual selected[selection_size];

    // Start the "sweep" across the population
    for (int i = 0; i < selection_size; i++) {
        int pointer = start + i * distance;

        // Linearly traverse the population to find the individual
        int cumulative_fitness = 0;
        int idx = 0;
        while (cumulative_fitness < pointer) {
            cumulative_fitness += population[idx].fitness;
            idx++;
        }

        selected[i] = population[idx];
    }

    *population = *selected;
}

void truncate_selection(individual population[], int population_size, int selection_size) {

    individual selected[selection_size];

    qsort(population, population_size, sizeof(individual), compare_individuals_by_fitness);

    // Select the top selection_size individuals
    for (int i = 0; i < selection_size; i++) {
        selected[i] = population[i];
    }

    // Replace the original population with the selected individuals
    for (int i = 0; i < selection_size; i++) {
        population[i] = selected[i];
    }
}