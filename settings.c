#include <stdlib.h>
#include "settings.h"

void check_argument_size(int argc, char* program_name){
    // Needs filename for work and population number
    if(argc != 5){
        printf("Usage:\n");
        printf("%s <filename> <parent size> <recombination size> <rounds>\n", program_name);
        exit(EXIT_FAILURE);
    } 
}

void load_settings(setting* settings, char* argv[]){
    settings->file_name = argv[1];
    settings->parent_size = atoi(argv[2]); 
    settings->recombination_size = atoi(argv[3]);
    settings->rounds = atoi(argv[4]);
    settings->offspring_size = settings->parent_size + settings->recombination_size;
    settings->population_size = settings->parent_size + settings->offspring_size;
}

void check_settings_values(setting* settings){
    if(settings->parent_size < 1){
        printf("Parent size must be at least 1\n");
        exit(EXIT_FAILURE);
    }
    if(settings->recombination_size < 1){
        printf("Recombination size must be at least 1\n");
        exit(EXIT_FAILURE);
    }
    if(settings->rounds < 1){
        printf("Rounds must be at least 1\n");
        exit(EXIT_FAILURE);
    }
}

void load_check_settings(setting* settings, int argc, char* argv[]){
    check_argument_size(argc, argv[0]);
    load_settings(settings, argv);
    check_settings_values(settings);
}

void print_setting(setting* settings){
    printf("Settings:\n");
    printf("File name: %s\n", settings->file_name);
    printf("Parent size: %i\n", settings->parent_size);
    printf("Recombination size: %i\n", settings->recombination_size);
    printf("Rounds: %i\n", settings->rounds);
    printf("Offspring size: %i\n", settings->offspring_size);
    printf("Population size: %i\n", settings->population_size);
    printf("\n");
}