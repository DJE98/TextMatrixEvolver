#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evaluation.h"
#include "population.h"
#include "recombination.h"
#include "selection.h"
#include "mutation.h"
#include "settings.h"

void print_round_update(individual population[], setting current_settings, int current_round){        
    printf("\nCurrent round %i from %i\n", current_round, current_settings.rounds);
    print_best_individual(population, current_settings.parent_size);
    print_population(population, current_settings.parent_size);
}

int main(int argc, char* argv[])
{
    srand(1);

    setting current_settings;
    check_and_load_settings(&current_settings, argc, argv);
    print_setting(&current_settings);

    individual population[current_settings.population_size];
    generate_random_population(population, 10, 10, current_settings.population_size);
    
    for(int current_round = 0; current_round < current_settings.rounds; current_round++){
        /*
        if (current_round % 1000 == 0){
            population_size /= 2;
            parent_size /= 2;
            offspring_size /= 2;
        }
        */
        individual *offspring = &population[current_settings.parent_size];
        two_point_crossover(offspring, current_settings.parent_size, current_settings.recombination_size, 10, 10);
        mutation(offspring, current_settings.offspring_size); // Should I mutate also recombination?
        evaluate_population_by_file(current_settings.file_name, offspring, current_settings.offspring_size);
        if(current_round % 9 == 0 || current_round % 9 == 1 || current_round % 9 == 2){
           stochastic_universal_sampling(population, current_settings.population_size, current_settings.parent_size);
        }else{
           truncate_selection(population, current_settings.population_size, current_settings.parent_size);
        }
        if (current_round % 1000 == 0){
            print_round_update(population, current_settings, current_round);
        }
    }
    free_population(population, current_settings.population_size);
    return 0;
}