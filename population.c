#include "population.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void generate_random_individual(individual* one_individual, int x, int y){
    int size = x * y + 1; // One element for null termination
    one_individual->genome = (char*) calloc(size, sizeof(char));
    for (int current_pos = 0; current_pos < size-1; current_pos++){
        one_individual->genome[current_pos] = 'A' + (random() % 26);
    }
    one_individual->genome[size-1] = '\0'; // Manual null termination of string
    one_individual->fitness = 0;
}

void generate_random_population(individual population[], int x, int y, int number){
    for(int position = 0; position < number; position++){
        generate_random_individual(&population[position], x, y);
    } 
}

void free_population(individual population[], int number){
    for(int position = 0; position < number; position++){
        free(population[position].genome);
    } 
}

void print_population(individual population [], int population_size){
    printf("\nPopulation:\n");
    for(int position = 0; position < population_size; position++){
        printf("%s \t %i\n", population[position].genome, population[position].fitness);
    }
}

void print_best_individual(individual population [], int population_size){
    printf("\nBest Individual:\n");
    qsort(population, population_size, sizeof(individual), compare_individuals_by_fitness);
    individual* best_individual = &population[0];
    printf("%s \t %i\n", best_individual->genome, best_individual->fitness);
}

int compare_individuals_by_fitness(const void *a, const void *b) {
    individual *individual_a = (individual *) a;
    individual *individual_b = (individual *) b;

    return (individual_b->fitness - individual_a->fitness);
}