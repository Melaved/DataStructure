#pragma once
//! \brief Structure for a queue implemented using a circular buffer.
struct QueueByBuffer
{
    CircularBuffer* Buffer;  
};

//! \brief Creates and initializes a queue using a circular buffer.
//! \return Pointer to the created queue.
QueueByBuffer* CreateQueueByBuffer();

//! \brief Adds an element to the end of the queue.
//! param queue Pointer to the queue where the element will be added.
//! param data The value to be added to the queue.
void Enqueue(QueueByBuffer* queue, int data);

//! \brief Removes and returns the front element from the queue.
//! param queue Pointer to the queue from which the element will be removed.
//! \return Value of the removed element.
int Dequeue(QueueByBuffer* queue);

//! \brief Frees the memory occupied by the queue and its buffer.
//! param queue Pointer to the queue that needs to be deleted.
void DeleteQueue(QueueByBuffer* queue);
