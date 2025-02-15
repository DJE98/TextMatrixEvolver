#include "unity.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../population.h"

void setUp(void) { }
void tearDown(void) { }

// Test to check if the individual's fitness is 0
void test_individual_fitness(void) {
    individual test_individual;
    int x = 5, y = 5;

    set_random_seed(1234);

    generate_random_individual(&test_individual, x, y);

    TEST_ASSERT_EQUAL_INT_MESSAGE(0, test_individual.fitness, "Fitness is not initialized to 0");

    free(test_individual.genome);
}

// Test to check if the genome is of correct length
void test_genome_length(void) {
    individual test_individual;
    int x = 5, y = 5;

    set_random_seed(1234);

    generate_random_individual(&test_individual, x, y);

    int expected_length = x * y;
    TEST_ASSERT_EQUAL_INT_MESSAGE(expected_length, strlen(test_individual.genome), "Genome length is incorrect");

    free(test_individual.genome);
}

// Test to check if the genome string is null-terminated
void test_genome_termination(void) {
    individual test_individual;
    int x = 5, y = 5;

    set_random_seed(1234);

    generate_random_individual(&test_individual, x, y);

    int expected_length = x * y;
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('\0', test_individual.genome[expected_length], "Genome string is not null-terminated");

    free(test_individual.genome);
}

// Test to check if all characters in genome are uppercase alphabets
void test_genome_characters(void) {
    individual test_individual;
    int x = 5, y = 5;

    set_random_seed(1234);

    generate_random_individual(&test_individual, x, y);

    int expected_length = x * y;
    for (int i = 0; i < expected_length; i++) {
        TEST_ASSERT_TRUE_MESSAGE(isupper(test_individual.genome[i]), "Genome contains non-uppercase character");
    }

    free(test_individual.genome);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_individual_fitness);
    RUN_TEST(test_genome_length);
    RUN_TEST(test_genome_termination);
    RUN_TEST(test_genome_characters);

    return UNITY_END();
}