#ifndef EVALUATION_H_INCLUDED
#define EVALUATION_H_INCLUDED
#include "population.h"

/**
 * @brief Evaluates whether a given word is present in a genome sequence
 *
 * This function is designed to search for a particular word in a given genome sequence. 
 * It uses a case-insensitive comparison, traversing through the genome sequence character by character.
 * If the entire word is found in the sequence, the function will return 1, otherwise it will return 0.
 *
 * @note The function assumes that both input strings are null-terminated. 
 * Make sure to only pass in properly formed, null-terminated C-style strings.
 * Also note that the word to be searched should not be longer than the genome sequence, 
 * otherwise the function will immediately return 0.
 * 
 * @param word A null-terminated C-string representing the word to be found in the genome. 
 *        This word should only contain alphabetical characters and should not exceed the length of the genome.
 *        The function treats the search as case-insensitive, so it doesn't matter whether characters are in lower-case or upper-case.
 * @param genome A null-terminated C-string representing the genome sequence in which the word will be searched.
 *        It is assumed that the genome sequence only contains alphabetical characters.
 *
 * @return Returns 1 if the entire word is found in the genome sequence, otherwise it returns 0.
 */
int evaluate_word(char* word, char* genome);

/**
 * @brief Evaluates an individual by comparing its genome to words in a specified file
 * 
 * This function reads a file line by line, where each line is treated as a separate word. 
 * The function calls `evaluate_word` on each line (word) to check if it is present in the individual's genome. 
 * The individual's fitness is incremented by the return value of `evaluate_word`, which is either 1 (if the word is found) or 0 (if not).
 * 
 * @note The function checks if the file is accessible for reading and will exit with an error message if it is not. 
 * It's also assumed that the lines in the file do not exceed 256 characters. Lines longer than this will be cut off, which may impact the result.
 * 
 * @param fileName A null-terminated C-string representing the name (and path, if necessary) of the file to be read. 
 *        Each line of the file should represent a single word to be searched in the individual's genome.
 * @param one_individual A pointer to the individual struct that is to be evaluated. 
 *        The function expects this to be a valid pointer to a struct with at least one genome. 
 *        The struct's fitness field will be updated by this function.
 *
 * @return void
 */
void evaluate_individual_by_file(const char* fileName, individual* one_individual);

/**
 * @brief Evaluates a population of individuals by comparing each individual's genome to words in a specified file
 * 
 * This function traverses through a population of individuals and calls `evaluate_individual_by_file` on each individual. 
 * The function `evaluate_individual_by_file` reads a file line by line, where each line is treated as a separate word. 
 * It then checks if each word is present in the individual's genome, incrementing the individual's fitness value accordingly.
 * 
 * @note The function checks if the file is accessible for reading and will exit with an error message if it is not.
 * It's also assumed that the lines in the file do not exceed 256 characters. Lines longer than this will be cut off.
 * The function also assumes that the population array is large enough to accommodate the specified number of individuals.
 * Make sure to only pass in a population array that has at least 'number' elements to prevent accessing out of bounds memory.
 * 
 * @param file_name A null-terminated C-string representing the name (and path, if necessary) of the file to be read. 
 *        Each line of the file should represent a single word to be searched in the individual's genome.
 * @param population A pointer to the first individual in the population array that is to be evaluated. 
 *        The function expects this to be a valid pointer to an array of individuals, each with at least one genome. 
 *        The 'fitness' field of each individual struct in the array will be updated by this function.
 * @param number The number of individuals in the population array. This must be less than or equal to the size of the population array.
 *
 * @return void
 */
void evaluate_population_by_file(const char* file_name,individual*  population, int number);

#endif