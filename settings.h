# ifndef SETTINGS_H
# define SETTINGS_H

typedef struct setting{
    char* file_name;
    int parent_size;
    int recombination_size;
    int rounds;
    int offspring_size;
    int population_size;
} setting;

void check_argument_size(int argc, char* program_name);
void load_settings(setting* settings, char* argv[]);
void check_settings_values(setting* settings);
void load_check_settings(setting* settings, int argc, char* argv[]);
void print_setting(setting* settings);

#endif