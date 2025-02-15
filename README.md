# TextMatrixEvolver
The TextMatrixEvolver is an innovative project that leverages the power of evolutionary algorithms to generate character matrices of a defined size. These matrices are uniquely structured to visually display specific words from a given list.

## 📌 Features

- **Configurable evolutionary settings** (population size, recombination, mutation, and selection parameters).
- **Stochastic Universal Sampling and Truncation Selection** strategies.
- **Two-Point Crossover** for recombination.
- **Mutation and Evaluation** based on a provided dataset.
- **Periodic Logging** of the best individual and the population state.

## 📜 Usage

### Compilation

Ensure you have a C compiler (e.g., `gcc`) installed. Compile the program with:

```sh
gcc -o evolutionary_algorithm main.c settings.c evaluation.c population.c recombination.c selection.c mutation.c -Wall -O2
```

### Running the Program

Run the program with:

```sh
./evolutionary_algorithm <filename> <parent_size> <recombination_size> <rounds>
```

Example:

```sh
./evolutionary_algorithm data.txt 100 50 10000
```

### Parameters

- `<filename>`: The dataset file used for evaluation.
- `<parent_size>`: Number of parents selected each round.
- `<recombination_size>`: Number of offspring generated per round.
- `<rounds>`: Total number of evolutionary iterations.