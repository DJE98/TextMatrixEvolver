#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "population.h"
#include "ctype.h"

int evaluate_word(char* word, char* genome){
    int genome_position = 0;
    int word_position = 0;
    while(*(genome+genome_position) != '\0'){
        //Character from word is in matrix at the current position
        if (*(genome+genome_position) == toupper(*(word+word_position))){
            word_position++;
        }

        // Every character from word was founded
        if (*(word+word_position) == '\0'){
            return 1;
        }

        genome_position++;
    }
    return 0;
}

void evaluate_individual_by_file(const char* fileName, individual* one_individual){
    FILE* file = fopen(fileName, "r");
    if (!file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char line[256];
    one_individual->fitness = 0;
    while (fgets(line, sizeof(line), file)) { 
        line[strcspn(line, "\n")] = 0; // Delete line break
        one_individual->fitness += evaluate_word(line, one_individual->genome);
    }
    fclose(file);
}

void evaluate_population_by_file(const char* file_name,individual*  population, int number){
    for (int position = 0; position < number; position++){
        evaluate_individual_by_file(file_name, &population[position]);
    }
}

