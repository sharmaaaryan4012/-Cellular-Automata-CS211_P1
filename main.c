// Name: Aaryan Sharma
// CS 211 (Fall 2023) - Prof Scott Reckinger
// Project -1: Elementary Cellular Automaton

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


const int WORLD_SIZE = 65;


typedef struct cell_struct{
    bool state[3]; //active status for [left, me, right] cells
    bool active; //current active status forp,m this cell
} cell;


bool setBitArray(bool bitArray[8], int rule) {

    // updates the bitArray with boolean values obtained from decimal to binary conversion of the integer "rule".

    if (rule > 0 && rule <= 255) {                                                                // the function executes only when the rule parameter lies in the range of 0-255.
        int i = 0;
        while (rule > 0) {                                                                         // while loop is used to compute the 8-bit binary value of the "rule" parameter.
            bitArray[i] = rule % 2;
            rule /= 2;
            i++;
        }

        return true;
    }

    else if (rule == 0) {
        for (int i=0; i<8; i++) {
            bitArray[i] = 0;
        }
        return true;
    }

    return false;
}


int stateToIndex(bool state[3]) {
    // Task 4 - Converts a 3-bit state array to the associated index of the rule.
    int status = 0;

    for (int i=2; i>=0; i--) {
        if (state[i] == 1) {
            status += pow(2, 2-i);                                                                   // If the state is 1, then the respective value is added to status.
        }
    }

    return status;
}


void setStates(cell world[WORLD_SIZE]) {
    // Task 5 - status for the nearby [left, me, right] cells.

    for (int i=0; i<WORLD_SIZE; i++) {                                                             // For loop is used to update the "state" array for each element in "world".
        if (i==0) {                                                                                // Seperate cases for first and last elements, due to the wrapping nature of the world.
            world[i].state[0] = world[WORLD_SIZE-1].active;
            world[i].state[1] = world[i].active;
            world[i].state[2] = world[i+1].active;
        }

        else if (i == WORLD_SIZE-1) {
            world[i].state[0] = world[i-1].active;
            world[i].state[1] = world[i].active;
            world[i].state[2] = world[0].active;
        }

        else {
            world[i].state[0] = world[i-1].active;
            world[i].state[1] = world[i].active;
            world[i].state[2] = world[i+1].active;
        }
    }

    return;
}


void evolveWorld(cell world[WORLD_SIZE], bool ruleBitArray[8]) {
    // Task 7 - evolve each cell's active status to the next generation using its state array

    for (int i=0; i<WORLD_SIZE; i++) {
        world[i].active = ruleBitArray[stateToIndex(world[i].state)];
    }

    return;
}


void displayState(cell world[WORLD_SIZE]) {                                                        // Function prints out the current state of the "world" array.

    for (int i=0; i<WORLD_SIZE; i++) {
        if (world[i].active == 1) {
            printf("*");
        }

        else {
            printf(" ");
        }
    }
    printf("\n");

    return;
}


int main() {
    cell world[WORLD_SIZE];
    printf("Welcome to the Elementary Cellular Automaton!\n");


    // Task - 2: generate the bit array for the user-specified rule
    int rule = 0;
    bool bitArray[8];
    printf("Enter the rule # (0-255): \n");
    scanf("%d", &rule);

    while (!(setBitArray(bitArray, rule))) {                                                       // while loop runs and updates the value of "rule" until it holds a valid value.
        printf("Enter the rule # (0-255): \n");
        scanf("%d", &rule);
    }

    printf("\nThe bit array for rule #%d is ", rule);
    for (int i=7; i>=0; i--) {
        printf("%d", bitArray[i]);
    }

    printf("\n");


    // Task 3 - use the rule bit array to report the evolution
    printf("\nThe evolution of all possible states are as follows:\n");
    printf("|***|   |** |   |* *|   |*  |   | **|   | * |   |  *|   |   |\n");                     // Recurring printf statement.

    for (int j=7; j>=0; j--) {                                                                     // loops through the bitArray and prints out the evolution steps.
        printf(" |");

        if (bitArray[j] == 0) {
            printf(" ");
        }

        else {
            printf("*");
        }

        printf("|    ");
    }
    printf("\n");


    // Task 6 -initialize the world with ONLY the middle cell active.
    int gen = 0;
    printf("\nEnter the number of generations: ");
    scanf("%d", &gen);
    printf("\nInitializing world & evolving...\n");

    for (int k=0; k<WORLD_SIZE; k++) {
        if (k == (WORLD_SIZE/2)) {
            world[k].active = 1;                                                                   // Only for the first gen, the middle cell of the world is active.
        }

        else {
            world[k].active = 0;
        }
    }
    setStates(world);
    displayState(world);


    // Task 8 - evolve the world the user-specified number
    for (int l=0; l<(gen-1); l++) {
        evolveWorld(world, bitArray);
        setStates(world);
        displayState(world);
    }

    return 0;
}