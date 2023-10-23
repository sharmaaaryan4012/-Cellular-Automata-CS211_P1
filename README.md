# Elementary Cellular Automaton Project

## Introduction

In this project, we implement the simplest version of a one-dimensional cellular automaton, a collection of cells on a specified grid. Each cell can be either active or inactive, and rules are specified to evolve the status of each cell based on the statuses of its nearest neighbors.

Conway's Game of Life is a well-known example of a two-dimensional cellular automaton, but we focus on a one-dimensional version in this project. The evolution of the cells depends on their current state and the state of their immediate neighbors to the left and right.

## Scope and Limitations

- The world will ALWAYS have a size of 65 cells (defined by the global constant variable `WORLD_SIZE`).
- The initial world (generation 0) starts with a single active cell in the middle of the world (at index 32).
- Evolution rules ALWAYS use a 3-bit state for each cell, determined by the cell itself and its immediate neighbors to the left and right.
- The world is circular, meaning the left neighbor of the first cell is the last cell, and vice versa.
- The rule number must be an integer between 0 and 255, which can be represented as an 8-bit binary number.

## Implementation

The project is implemented in C, with each cell of the world represented as a struct with the following definition:

```c
typedef struct cell_struct {
  bool state[3]; // active status for [left, me, right] cells
  bool active;   // current active status for this cell
} cell;
```

The world is represented as an array of `cell` structs:

```c
cell world[WORLD_SIZE];
```

## Tasks and Milestones

1. **setBitArray()**: Convert the input integer rule to its binary representation and store it in a bool array `bitArray[8]`.

2. **initializeWorld()**: Initialize the world with all cells inactive except for the middle cell.

3. **printWorld()**: Print the current state of the world.

4. **updateCellActiveStatus()**: Update the active status of a cell based on the evolution rules.

5. **updateCellState()**: Update a cell's state array based on its neighbors' active statuses.

6. **evolveWorld()**: Evolve the world to the next generation.

7. **main()**: Implement the primary function to handle user input, initialize the world, and evolve the world for a specified number of generations.

8. **Additional Tasks**: Add additional features or optimizations as necessary.


## How to Run

1. Compile the C code using a C compiler like GCC: `gcc main.c -o cellular_automaton`
2. Run the compiled program: `./cellular_automaton.`
3. Follow the on-screen prompts to enter the rule number and number of generations.

## Contributing

You can fix this repository and submit pull requests to contribute to this project. Just so you know, all contributions are welcome.

## License

This open-source project is available under the [MIT License](LICENSE.md).
