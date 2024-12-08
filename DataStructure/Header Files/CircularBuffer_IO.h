#pragma once
#include <iostream>
#include "..\header files\CircularBuffer.h"
using namespace std;

/*
 * @brief Displays the menu for interacting with a circular buffer.
 */
void ShowCircularBufferMenu();


/*
 * @brief Prints the contents of a circular buffer to the console.
 *
 * @param buffer A pointer to the CircularBuffer structure to be printed.
 */
void PrintCircularBuffer(CircularBuffer* buffer);


/*
 * @brief Handles user input and performs operations on a circular buffer based on the user's choice.
 *
 * @param buffer A pointer to the CircularBuffer structure to be manipulated.
 */
void CircularBufferShoice(CircularBuffer* buffer);
