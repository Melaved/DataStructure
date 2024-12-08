#pragma once
#include <iostream>
#include "..\header files\Stack.h"
using namespace std;


/*
 * @brief Displays the menu for stack operations.
 */
void ShowStackMenu();

/*
 * @brief Prints the contents of a stack to the console.
 *
 * @param stack A pointer to the Stack structure to be printed.
 */
void PrintStack(Stack* stack);

/*
 * @brief Handles user input and performs operations on a stack based on the user's choice.
 *
 * @param stack A pointer to the Stack structure to be manipulated.
 */
void StackChoice(Stack* stack);
