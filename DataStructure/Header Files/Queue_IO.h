#pragma once
#include "..\header files\QueueByBuffer.h"
#include "..\header files\QueueByStacks.h"
#include "..\header files\CircularBuffer_IO.h"


/*
 * @brief Displays the menu for queue operations (using both buffer and stacks implementations).
 */
void ShowQueueMenu();

/*
 * @brief Prints the contents of a queue implemented using a circular buffer.
 *
 * @param queue A pointer to the QueueByBuffer structure to be printed.
 */
void PrintQueueByBuffer(QueueByBuffer* queue);


/*
 * @brief Prints the contents of a stack to the console.
 *
 * @param stack A pointer to the Stack structure to be printed.
 */
void PrintStackForQueue(Stack* stack);

/*
 * @brief Prints the contents of a queue implemented using two stacks.
 *
 * @param queue A pointer to the QueueByStacks structure to be printed.
 */
void PrintQueueByStacks(QueueByStacks* queue);

/*
 * @brief Handles user input and performs operations on a queue implemented using a circular buffer.
 *
 * @param queueByBuffer A pointer to the QueueByBuffer structure to be manipulated.
 */
void QueueByBufferChoice(QueueByBuffer* queueByBuffer);

/*
 * @brief Handles user input and performs operations on a queue implemented using two stacks.
 *
 * @param queue A pointer to the QueueByStacks structure to be manipulated.
 */
void QueueByStacksChoice(QueueByStacks* queue);

