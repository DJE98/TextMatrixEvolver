#include "recombination.h"
#include<stdlib.h>
#include<string.h>

void two_point_crossover(individual population[], int parent_size, int offspring_size, int x, int y){
    for(int round = 0; round < offspring_size; round = round + 2){
        individual* parent1 = &population[rand() % parent_size];
        individual* parent2 = &population[rand() % parent_size];
        individual* offspring1 = &population[parent_size + round];
        individual* offspring2 = &population[parent_size + round + 1];
        
        // Generate two random crossover points
        int crossover_point1 = rand() % (x * y);
        int crossover_point2 = rand() % (x * y);

        // If points are the same, adjust second one
        if(crossover_point1 == crossover_point2) {
            crossover_point2 = (crossover_point2 + 1) % (x * y);
        }

        // Ensure point1 is always smaller than point2
        if(crossover_point1 > crossover_point2) {
            int temp = crossover_point1;
            crossover_point1 = crossover_point2;
            crossover_point2 = temp;
        }

        // Copy the genomes of the parents to the offspring
        strcpy(parent1->genome, offspring1->genome);
        strcpy(parent2->genome, offspring2->genome);

        // Perform the crossover between crossover points
        for (int i = crossover_point1; i < crossover_point2; i++) {
            // Swap the genes at position i
            char temp = offspring1->genome[i];
            offspring1->genome[i] = offspring2->genome[i];
            offspring2->genome[i] = temp;
        }

        // Set default fitness for offsprings
        offspring1->fitness = 0;
        offspring2->fitness = 0;
    }
}